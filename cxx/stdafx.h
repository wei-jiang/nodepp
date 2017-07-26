#pragma once
// #define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <cstdio>
#include <cstdlib>

#include <memory>
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <map>
#include <queue>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
//#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/property_tree/ptree.hpp> 
#include <boost/property_tree/json_parser.hpp>
#include <boost/convert.hpp>
#include <boost/convert/lexical_cast.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
namespace pt = boost::property_tree;

#include "freego.h"


#pragma warning(disable:4818 4819)
template <typename T>
struct FGST
{
    FGST(const FGST&) = delete;
    FGST& operator=(const FGST&) = delete;
protected:
    FGST(){}
public:
    typedef T object_type;

    static object_type* instance()
    {
      static object_type obj;
      return &obj;
    }
};
typedef unsigned char byte;
struct TLVEntity;
typedef std::vector< std::shared_ptr<TLVEntity> > TLV_VEC;
struct TLVEntity {
	std::string tag;         //标记
	std::string length;      //数据长度
	std::string val;       //数据
	int len() const
	{
		if (1 == length.length() )
		{
			return length[0];
		}
		else
		{
			int len_size = length[0] & 0x7f;
			//从下一个字节开始算Length域
			int lv = 0;
			for (int i = 1; i < len_size; ++i)
			{
				lv += length[i] << (i * 8); //计算Length域的长度
			}
			return lv;
		}		
	}
	std::pair<std::string, std::string> get_pair()
	{
		return std::make_pair(tag, val);
	}
	std::string get_str()
	{
		return tag + length + val;
	}
	TLV_VEC sub_tlvs;   //子嵌套TLV实体
};
std::string random_string( size_t length );
std::string string_to_hex(const std::string& input);
std::string decodeHex(const std::string & source);
uint32_t bcd2int(byte* bcd, size_t length);