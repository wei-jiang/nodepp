#include "async_io.h"
#include "hvipc.h"
#include "udp_dealer.h"

boost::asio::io_service AsyncIO::_ioService;
using namespace std;
using namespace boost;
using namespace boost::asio;
void init(const std::string& cfg)
{
    AsyncIO::instance()->init(cfg);
}

void AsyncIO::routine(const boost::system::error_code& /*e*/, boost::asio::deadline_timer* t )
{
	// FREEGO_INFO <<"AsyncIO::routine...";
	t->expires_at(t->expires_at() + boost::posix_time::seconds(3)); //3 seconds
	t->async_wait(boost::bind( &AsyncIO::routine, this,
		boost::asio::placeholders::error, t ));
}
AsyncIO::AsyncIO()
	:_resolver(_ioService), 
	_timer(new boost::asio::deadline_timer(_ioService, boost::posix_time::seconds(1) ) )
		
{
	// FREEGO_INFO << "AsyncIO::AsyncIO()";	
}


AsyncIO::~AsyncIO()
{

}
int AsyncIO::schedule_task(float seconds, std::function<int()> dealer)
{
	TimerPtr t = get_timer(seconds);
	t->async_wait(boost::bind(&AsyncIO::task_wrapper, this, boost::asio::placeholders::error, _timer.get(), dealer ));  
}
TimerPtr AsyncIO::get_timer(float second)
{
	return TimerPtr(new boost::asio::deadline_timer(_ioService, boost::posix_time::seconds( second ) ) );
}
void AsyncIO::task_wrapper(const boost::system::error_code& /*e*/, 
							boost::asio::deadline_timer* t, 
							std::function<int()> dealer )
{
	int ret = dealer();
	if(ret != 0)
	{
		t->async_wait(boost::bind( &AsyncIO::task_wrapper, this,
			boost::asio::placeholders::error, t, dealer ));
	}
}
void AsyncIO::init(const std::string& cfg) {

	_timer->async_wait(boost::bind(&AsyncIO::routine, this, boost::asio::placeholders::error, _timer.get() ));    
    std::thread ioThread(&AsyncIO::run, this);
	ioThread.detach();
	std::stringstream ss;
	ss << cfg;
	FREEGO_INFO << cfg;
	pt::ptree root;

	boost::property_tree::read_json(ss, root);
	_cfg.node_udp_port = root.get<int>("node_udp_port");	
	_cfg.cxx_udp_port = root.get<int>("cxx_udp_port");

	_udp.reset( new UdpDealer(_ioService, _cfg.cxx_udp_port) );

	// _hvdev = new ()
	// ret = _skb->init(_cfg.pp_port);
	// if(0 == ret)
	// {
	// 	FREEGO_INFO <<"open secret keyboard success";
	// }
	// else
	// {
	// 	FREEGO_INFO <<"open secret keyboard failed";
	// }
}

void AsyncIO::run()
{
	try 
	{
		_ioService.run();
	}
	catch (system::system_error &e) {
		FREEGO_FATAL << "Error occured!"
			<< " Error code = " << e.code()
			<< ". Message: " << e.what();
	}	
}
void AsyncIO::stop()
{
    _ioService.stop();
	_ioService.reset();
}