#ifndef   _zjdm_H_       
#define   _zjdm_H_

#include<iostream>
#include<string>
#include<fstream>

#include"cifa.h"

using namespace std;


/*
����������м����������
*/
class CodeGeneration : public LexicalAnalyzer
{
public:
	void initMyCode();
	int getVariable(string key);
	string getConstValue(string key);
	bool getConst(string key);
	void print();

	CodeGeneration()
	{
		read = 0;
		write = 0;
		flag = 0;
		initMyCode();
	};
	int flag = 0;
	int read;
	int write;
	struct codeNode myCode[200];
};

#endif