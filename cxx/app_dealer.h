#pragma once

#include "json/json.h"

class UdpDealer;
class LRT 
{
    UdpDealer* _udp;    
    Json::Value _in, _out;
public:
    int repeat;
    LRT(Json::Value& in, Json::Value& out, UdpDealer* udp)
        :repeat(1), _udp(udp), _in(in), _out(out){}
    virtual ~LRT();
    int do_routine(){
        do_task();
        return finish_up();
    }
    virtual void do_task(){
        std::stringstream ostr;
        ostr<< _in["cmd"].asString() <<" : "<< _in["tid"].asInt() << " : this is long term run long";
        _out["log"] = ostr.str();
    }
private:
    int finish_up();
};
class UdpDealer;
class AppDealer;
typedef std::map<std::string, std::function<int(AppDealer*, Json::Value& in, Json::Value& out)>> Cmd2DealerMap;
class AppDealer
{
    UdpDealer* _udp;
public:
    AppDealer(UdpDealer* udp);
    int dispatch(Json::Value& in, Json::Value& out);
private:
    int test(Json::Value& in, Json::Value& out);
    int schedule_task(Json::Value& in, Json::Value& out);
    int unschedule_task(Json::Value& in, Json::Value& out);  
private:
    static std::map<int, LRT*> _lrts;
    static Cmd2DealerMap _dealers;
};


