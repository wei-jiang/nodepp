
#pragma once

class UdpDealer;
class HVDev;
typedef boost::shared_ptr<boost::asio::deadline_timer> TimerPtr;
class AsyncIO : public FGST<AsyncIO>
{
    static boost::asio::io_service _ioService;      
    boost::shared_ptr<boost::asio::deadline_timer> _timer;
    boost::asio::ip::udp::resolver _resolver;

public:
    boost::shared_ptr<UdpDealer> _udp;
    boost::shared_ptr<HVDev> _hvdev;
    struct 
    {
        short node_udp_port;
        short cxx_udp_port;
    } _cfg;
    // std::shared_ptr<UdpServer> m_udpServer;
public:
    int schedule_task(float seconds, std::function<int()> dealer);
    int post_udp(const std::string& data);
	void run();
    void stop();
	void init(const std::string& cfg);
    TimerPtr get_timer(float second);
	AsyncIO();
	~AsyncIO();
private:
	void routine(const boost::system::error_code& /*e*/, boost::asio::deadline_timer* t );
    void task_wrapper(const boost::system::error_code& /*e*/, boost::asio::deadline_timer* t, std::function<int()> dealer );

};