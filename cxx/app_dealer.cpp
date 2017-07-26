#include "common.h"
#include "async_io.h"
#include "app_dealer.h"
#include "udp_dealer.h"

using namespace std;
std::map<int, LRT*> AppDealer::_lrts;
Cmd2DealerMap AppDealer::_dealers = 
{
    {"test", &AppDealer::test},
    {"sch_task", &AppDealer::schedule_task},
    {"unsch_task", &AppDealer::unschedule_task}
};

LRT::~LRT(){
    FREEGO_TRACE << _in["cmd"].asString() <<" : "<< _in["tid"].asInt() <<" : LRT::~LRT()";
} 
int LRT::finish_up()
{
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(_out);
    _udp->do_send(output);
    ///////////////////////////
    int rp = repeat;
    if( 0 == rp) delete this;
    return rp;
}

AppDealer::AppDealer(UdpDealer* udp)
:_udp(udp)
{
    // _dealers.insert( make_pair("test1", &AppDealer::test1) );
    // _dealers.insert( make_pair("test2", &AppDealer::test2) );
}
int AppDealer::dispatch(Json::Value& in, Json::Value& out)
{
    std::string cmd = in["cmd"].asString();
    Cmd2DealerMap::iterator it = _dealers.find( cmd );
    if( it != _dealers.end() ) {
        it->second(this, in, out);
    } else {
        FREEGO_TRACE << cmd << " : dealer no found";
    }

}
int AppDealer::test(Json::Value& in, Json::Value& out)
{
    out["name"] = "Hello world";
    out["sex"] = 0;
    return 0;
}
int AppDealer::schedule_task(Json::Value& in, Json::Value& out)
{
    int tid = in["tid"].asInt();
    unschedule_task(in, out);
    _lrts[tid] = new LRT(in, out, _udp);
    AsyncIO::instance()->schedule_task( 2, boost::bind(&LRT::do_routine, _lrts[tid]) );
    out["ret"] = 0;
    return 0;
}
int AppDealer::unschedule_task(Json::Value& in, Json::Value& out)
{
    int tid = in["tid"].asInt();
    std::map<int, LRT*>::iterator it = _lrts.find(tid);
    if( it != _lrts.end() )
    {
        it->second->repeat = 0;
        _lrts.erase(it);
        out["ret"] = 0;
    } else {
        out["ret"] = -1;
    }
    return 0;
}
