#pragma once

using boost::asio::ip::udp;
class AppDealer;
class UdpDealer
{
public:
  UdpDealer(boost::asio::io_service& io_service, short port);

  void do_receive();
  void do_send(const std::string& data);

private:
  boost::shared_ptr<AppDealer> _app_do;
  udp::socket socket_;
  udp::endpoint sender_endpoint_;
  enum { max_length = 2048 };
  char data_[max_length];
};
