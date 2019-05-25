#ifndef   _cifa_H_       
#define   _cifa_H_
#include"my.h"

class LexicalAnalyzer
{
public:
	int count;             //数组中已有的词数量

	void  Init();
	void  analyzer();
	void  print();
	int  is_number_or_letter(char ch);
	int  find_syn(string cs);
	int  is_allnumber(string cs);   //判断字符串是否为纯数字 是返回1  不是返回0
	int Getsyn(int nowcount);
};

#endif