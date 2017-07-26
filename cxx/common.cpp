
#include "common.h"
#include "json/json.h"
using namespace std;


string test_cpp()
{    
    string ver = "Hello world from c++";
    FREEGO_TRACE <<"Hello world from c++";
    FREEGO_DEBUG <<"Hello world from c++";
    FREEGO_INFO <<"Hello world from c++";
    FREEGO_WARN <<"Hello world from c++";
    FREEGO_ERROR <<"Hello world from c++";
    FREEGO_FATAL <<"Hello world from c++";
    return ver;
}
string test_json(const string& para)
{    
    Json::Value root;
    root["name"] = "jiangwei";
	root["sex"] = 111;
    if( !para.empty() )
    {
        Json::Reader reader;
        Json::Value value;        
        try
        {
            if (reader.parse(para, value))
            {
                root["j"] = value["j"].asString();
                root["w"] = value["w"].asString();
            }
        }
        catch(...)
        {
            
        }
        
    }   
    Json::FastWriter fastWriter;
	std::string output = fastWriter.write(root);
    return output;
}
std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}
std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}
std::string decodeHex(const std::string & source)
{
	if (std::string::npos != source.find_first_not_of("0123456789ABCDEFabcdef"))
	{
		// you can throw exception here
		return{};
	}

	union
	{
		uint64_t binary;
		char byte[8];
	} value{};

	auto size = source.size(), offset = (size % 16);
	std::vector<uint8_t> binary{};
	binary.reserve((size + 1) / 2);

	if (offset)
	{
		value.binary = std::stoull(source.substr(0, offset), nullptr, 16);

		for (auto index = (offset + 1) / 2; index--; )
		{
			binary.emplace_back(value.byte[index]);
		}
	}

	for (; offset < size; offset += 16)
	{
		value.binary = std::stoull(source.substr(offset, 16), nullptr, 16);
		for (auto index = 8; index--; )
		{
			binary.emplace_back(value.byte[index]);
		}
	}

	return string( (char*)&binary[0], binary.size());
}
uint32_t bcd2int(byte* bcd, size_t length)
{
    uint32_t result(0);
    while (length--) {
        result = result * 100 + (*bcd >> 4) * 10 + (*bcd & 15);
        ++bcd;
    }
    return result;
}