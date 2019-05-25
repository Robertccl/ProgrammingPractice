#include<iostream>
using namespace std;

#include"my.h"
#include"cifa.h"
#include"yufa.h"

using namespace std;


int ifflag = 0, whileflag = 0, beginflag = 0, bracketflag = 0;
int snum = 0;
int t = 0, l = 0;
int codeflag = 0;//表示变量的个数，超过两个，就产生连乘，

int main()
{
	GrammerAnalyzer GA;
	GA.Init();
	GA.analyzer();
	GA.print();
	GA.GraInit();
	GA.uptodown();
	CodeGeneration CG = CodeGeneration();

	CG.print();
	for (int i = 0; i < t; i++)
	{
		cout << code[i].statement << endl;
	}

	int a;
	cin >> a;
	return 0;
}