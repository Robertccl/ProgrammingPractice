#ifndef   _cifa_H_       
#define   _cifa_H_
#include"my.h"

class LexicalAnalyzer
{
public:
	int count;             //���������еĴ�����

	void  Init();
	void  analyzer();
	void  print();
	int  is_number_or_letter(char ch);
	int  find_syn(string cs);
	int  is_allnumber(string cs);   //�ж��ַ����Ƿ�Ϊ������ �Ƿ���1  ���Ƿ���0
	int Getsyn(int nowcount);
};

#endif