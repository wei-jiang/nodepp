#pragma once

#include "hvdevice/HvDeviceNew.h"
#pragma comment(lib, __FILE__"\\..\\HvDevice.lib") 
class AsyncIO;
class HVDev
{
public:
	HVDev(const std::string& ip, AsyncIO* paio);
	~HVDev();
	int open_dev();
	void refresh()
	{
		m_ap = std::chrono::steady_clock::now();
	}
	int check_ipc();
private:
	//active point
	decltype( std::chrono::steady_clock::now() ) m_ap;
	//expire seconds
	static std::chrono::seconds m_es;
	AsyncIO* _p_aio;
	std::string m_ip;
	HVAPI_HANDLE_EX m_hHv;
	static int __cdecl GetStringCallBack(PVOID pUserData, LPCSTR pString, DWORD dwStrLen);
	static std::map<std::string, std::string> m_ip2locMap;

};



