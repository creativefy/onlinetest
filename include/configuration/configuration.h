///
/// @file    configuration.h
/// @author
/// @date    2018-07-18 11:08:54
///
#ifndef __CC_CONFIGURATION_H__
#define __CC_CONFIGURATION_H__
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
using std::map;
using std::string;
using std::cout;
using std::endl;
using std::set;
using std::vector;
namespace cc
{
	class Configuration
	{
		
		public:
			static Configuration & getInstance();
		public:
			map<string,string> & getConfMap();
			set<string> getStopWordList();
		private:
			Configuration(const string &);
		private:
			string _confFilePath;
			map<string,string> _confMap;
			set<string> _stopWordList;//停用词
			static Configuration _instance;
	};
}//namespace cc
#endif
