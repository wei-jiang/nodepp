#include "common.h"
#include "udp_dealer.h"
#include "json/json.h"
#include "app_dealer.h"
/*
inter json prerequisite
{
    uid:"546567uy4657",
    cmd:"reg_log",
    payload:""
    //or other things below
    ...
}
*/
UdpDealer::UdpDealer(boost::asio::io_service& io_service, short port)
    : socket_(io_service, udp::endpoint(udp::v4(), port)),
    _app_do(new AppDealer(this))
{
    do_receive();
}
void UdpDealer::do_receive()
{    
    socket_.async_receive_from(
        boost::asio::buffer(data_, max_length), sender_endpoint_,
        [this](boost::system::error_code ec, std::size_t bytes_recvd)
        {
          if (!ec && bytes_recvd > 0)
          {
                std::string data(data_, max_length);
                Json::Reader reader;
                Json::Value in, out;        
                try
                {
                    if (reader.parse(data, in))
                    {
                        FREEGO_TRACE <<"uid=" << in["uid"].asString();
                        out["uid"] = in["uid"].asString();
                        _app_do->dispatch(in, out);
                    }
                }
                catch(...)
                {
                    FREEGO_TRACE <<"parse json failed";
                }
                
                Json::FastWriter fastWriter;
                std::string output = fastWriter.write(out);
                do_send(output);
          }
          do_receive();

        }
    );
}
void UdpDealer::do_send(const std::string& data)
{
    FREEGO_INFO << "do_send";
    socket_.async_send_to(
        boost::asio::buffer( data.c_str(), data.length() ), sender_endpoint_,
        [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
        {
          // do_receive();
        }
    );
}