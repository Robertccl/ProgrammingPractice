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
	int stateAnalyer();//������
	int variableAnalyer();//��ֵ���
	int expressionAnalyer();//�жϱ��ʽ
	int factorAnalyer();//�ж�����
	int complexAnalyer();//�������
	int conditionAnalyer();//�������
	int termAnalyer();//��������
	int loopAnalyer();//ѭ�����
	int napeAnalyer();
	void ceshi(int floor);
};
#endif