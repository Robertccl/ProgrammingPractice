#ifndef   _MY_H_       
#define   _MY_H_

#include<iostream>
using namespace std;

bool find_file_flag = true;
const int ERROR = -1;
const int EXIT = 0;
const int BEGIN = 1;
const int IF = 2;
const int THEN = 3;
const int WHILE = 4;
const int DO = 5;
const int END = 6;
const int CONST = 7;
const int VAR = 8;
const int VARIABLE = 10;
const int VALUE = 11;
const int PLUS = 13;
const int MINUS = 14;
const int MULTIPLE = 15;
const int DIVISION = 16;
const int COLON = 17;
const int COLONEQUALITY = 18;
const int LESSTHAN = 20;
const int NOEQUALITY = 21;
const int LESSEQUALITY = 22;
const int MORETHAN = 23;
const int MOREEQUALITY = 24;
const int EQUALITY = 25;
const int SEMICOLON = 26;
const int LEFTBRACKET = 27;
const int RIGHTBRACKET = 28;
const int COMMA = 29;
const int ELSE = 30;

struct wordTable
{
	string token;  //词
	int syn;     //种别码
};


struct codeNode2
{
	char variblar[10];
	string statement;
	char replacevariable[10];
};

/*
用于中间代码的结构体
*/
struct codeNode
{
	int type;//CONST|VARIABLE
	string variable;   //存放变量
	string value;   //存放语句
};

codeNode2 code[1000];
wordTable Table[28];   //字符表
wordTable myword[1000];  //储存词的数组


#endif