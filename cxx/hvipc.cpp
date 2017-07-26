
#include "common.h"
#include "hvipc.h"

#include "async_io.h"

using namespace std;
std::chrono::seconds HVDev::m_es(120);
std::map<std::string, std::string> HVDev::m_ip2locMap;
HVDev::HVDev(const std::string& ip, AsyncIO* paio)
	:m_ip(ip), m_hHv(NULL), _p_aio(paio), m_ap(std::chrono::steady_clock::now())
{
	m_ip2locMap["192.168.0.10"] = "scenic spot front door";
	m_ip2locMap["192.168.0.11"] = "scenic spot back door";
}

HVDev::~HVDev()
{
	if (m_hHv){
		HVAPI_CloseEx(m_hHv);
		m_hHv = NULL;
	}
}

int HVDev::open_dev()
{
	// 打开设备
	m_hHv = HVAPI_OpenEx(m_ip.c_str(), NULL);
	if (!m_hHv) {
		FREEGO_TRACE << m_ip << "打开设备失败";
		return -1;
	}
	HRESULT ret = HVAPI_SetCallBackEx(m_hHv, GetStringCallBack, this, 0, CALLBACK_TYPE_STRING, NULL);
	if (ret != S_OK) {
		FREEGO_TRACE << m_ip << "设置回调失败";
		return -1;
	}
	FREEGO_TRACE << m_ip << "设置回调成功";

	return 0;
}

int HVDev::GetStringCallBack(PVOID pUserData,
	LPCSTR pString,
	DWORD dwStrLen)
{
	HVDev* dev = (HVDev*)pUserData;
	string s(pString);
	int pos = s.find_first_of("in");
	s = s.substr(pos, s.length() - pos);

	// printf("%s的in,out数据=%s\n", dev->get_ip().c_str(), s.c_str() );
	// message::ptr nm = string_message::create("clzh");
	// message::ptr ip = string_message::create( dev->get_ip() );
	// //can not send chinese
	// string loc_str = m_ip2locMap[dev->get_ip()];
	// //cout << loc_str << endl;
	// message::ptr loc = string_message::create(loc_str);
	// message::ptr dt = string_message::create( s );
	// message::ptr om = object_message::create();
	// om->get_map()["s_name"] = nm;
	// om->get_map()["c_ip"] = ip;
	// om->get_map()["c_loc"] = loc;
	// om->get_map()["c_data"] = dt;
	dev->refresh();
	return 1;
}
int HVDev::check_ipc()
{
	auto cur = std::chrono::steady_clock::now();

	if (cur - m_ap > m_es)
	{
		return open_dev();
	}
	return 0;
}