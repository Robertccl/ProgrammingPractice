#ifndef   _yufa_H_       
#define   _yufa_H_

#include"zjdm.h"
#include"cifa.h"
using namespace std;

class GrammerAnalyzer : public LexicalAnalyzer
{
public:
	int nowcount;
	int kk;
	int floor;
	CodeGeneration CG = CodeGeneration();

	void GraInit();
	int  scanner();
	void uptodown();
	int constAnalyer();
	void errorPrimary();
	int varAnalyer();
	int stateAnalyer();//语句分析
	int variableAnalyer();//赋值语句
	int expressionAnalyer();//判断表达式
	int factorAnalyer();//判断因子
	int complexAnalyer();//复合语句
	int conditionAnalyer();//条件语句
	int termAnalyer();//条件分析
	int loopAnalyer();//循环语句
	int napeAnalyer();
	void ceshi(int floor);
};
#endif