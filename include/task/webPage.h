///
/// @file    webPage.h
/// @author  
/// @date    2018-07-28 10:58:42
///
#ifndef __CC_WEBPAGE_H__
#define __CC_WEBPAGE_H__
#include "configuration.h"
#include "wordSegmentation.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;
using std::map;
using std::set;
namespace cc
{

	class WebPage
	{
		public:
			WebPage();
			WebPage(const string & doc);
		public:
			int getDocId();//获取文档id
			string getDoc();//获取文档
			string getTitle();//获取标题
			string getUrl();//获取url
			string getSummary(const vector<string> & queryWords);//摘要
			map<string,int> & getWordMap();//获取文档的词频统计map
			void processDoc(Configuration & conf,WordSegmentation & jieba);//对格式化文档进行处理
			void calcTopK(vector<string> & wordsVec,int k,set<string> & stopWordList);//求取文档的topk词集
		private:
			const static int TOPK_NUMBER = 20;
			string _doc;//整篇文档
			bool _isProcessed;//标记是否被processDoc处理过
			int _docId;//文档id
			string _docTitle;//文档标题
			string _docUrl;//文档Url
			string _docContent;//文档内容
			string _docSummary;//文档摘要，自动生成，不固定
			vector<string> _topWords;//词频最高的前20个词
			map<string,int> _wordsMap;//保存每篇文档的所有词语和词频，不包括停用词
		public:
			friend bool operator==(const WebPage & lhs,const WebPage & rhs);//判断两篇文档是否相等
			friend bool operator<(const WebPage & lhs,const WebPage & rhs);//对文档按照docId进行排序
		public:
			class compator{//按照词频排序的比较对象
				public:
					bool operator()(const pair<string,int> & lhs,const pair<string,int> & rhs){
						if(lhs.second != rhs.second){
							return lhs.second > rhs.second;
						}
						return lhs.first < rhs.first;
					}
			};
	};

};//end of namespace

#endif
