#include"yufa.h"

void  GrammerAnalyzer::GraInit()
{
	nowcount = 0;
	CG.initMyCode();
	floor = 0;
}

int GrammerAnalyzer::scanner()
{
	int syn;
	syn = Getsyn(nowcount);
	nowcount++;
	return syn;
}

void GrammerAnalyzer::uptodown()
{
	if (find_file_flag == false)
		return;
	int Tp;
	int a;
	Tp = scanner();
	if (Tp == ERROR)
	{
		cout << "no code !!!!!!" << endl;
		return;
	}
	int status = 0;//判断语句匹配情况是否需要继续读入 0没有匹配到
	if (Tp == CONST || Tp == VAR)
	{
		if (Tp == CONST) {
			cout << "常量说明" << endl;
			floor++;
			ceshi(floor);
			cout << "Const" << endl;
			a = constAnalyer();
			floor--;
			if (a != ERROR) {
				cout << "CONST SUCCESS!!" << endl;
			}
			else
			{
				cout << "CONST ERROR" << endl;
			}
			Tp = scanner();
			if (Tp == VAR) {
				cout << "变量说明" << endl;
				floor++;
				ceshi(floor);
				cout << "Var" << endl;
				a = varAnalyer();
				floor--;
				if (a != ERROR)
				{
					cout << "VAR SUCCESS" << endl;
				}
				else
				{
					cout << "VAR ERROR" << endl;
				}
				Tp = scanner();
			}
		}
		else
		{
			cout << "变量说明" << endl;
			floor++;
			ceshi(floor);
			cout << "Var" << endl;
			a = varAnalyer();
			floor--;
			if (a != ERROR)
			{
				cout << "VAR SUCCESS" << endl;
			}
			else
			{
				cout << "VAR ERROR" << endl;
			}
			Tp = scanner();
			if (Tp == CONST) {
				cout << "常量说明" << endl;
				floor++;
				ceshi(floor);
				cout << "Const" << endl;
				a = constAnalyer();
				floor--;
				if (a != ERROR) {
					cout << "CONST SUCCESS!!" << endl;
				}
				else
				{
					cout << "CONST ERROR" << endl;
				}
				Tp = scanner();
			}
		}
	}
	a = nowcount + 1;
	if (a < count)
	{
		cout << "语句" << endl;
		nowcount--;
		floor++;
		stateAnalyer();
		floor--;
	}
}

void GrammerAnalyzer::ceshi(int floor)
{
	int a = floor * 10;
	for (int x = 0; x < a; x++)
		cout << " ";

}

//常量分析
int GrammerAnalyzer::constAnalyer() {
	int Tp;
	Tp = scanner();
	ceshi(floor);
	cout << "常量定义" << endl;
	if (Tp == VARIABLE)//标识符
	{
		if ((CG.getVariable(myword[nowcount - 1].token)) == -1)
		{
			cout << "error at  " << myword[nowcount - 1].token << " 使用未定义过的变量";
			return ERROR;

		}
		floor++;
		ceshi(floor);
		cout << "标识符 " << myword[nowcount - 1].token << endl;
		int a = scanner();//等号
		if (a == EQUALITY) {
			ceshi(floor);
			cout << "=" << endl;
			int b = scanner();
			if (b == VALUE) {
				ceshi(floor);
				cout << "无符号整数 " << myword[nowcount - 1].token << endl;
				int c = scanner();
				floor--;
				if (c == SEMICOLON) {//分号
					ceshi(floor);
					cout << ":" << endl;
					return c;
				}
				else if (c == COMMA) {//逗号
					ceshi(floor);
					cout << "," << endl;
					int d = constAnalyer();
					return d;
				}
				else
				{
					errorPrimary();
					return ERROR;
				}
			}
			else
			{
				errorPrimary();
				return ERROR;
			}
		}
		else {
			errorPrimary();
			//cout << "ERROR AT " << myword[nowcount].syn << endl;
			return ERROR;
		}
	}
	else {
		errorPrimary();
		//cout << "ERROR AT " << myword[nowcount].syn << endl;
		return ERROR;
	}
}

//变量分析
int GrammerAnalyzer::varAnalyer() {
	int Tp;
	Tp = scanner();
	ceshi(floor);
	cout << "变量定义" << endl;
	if (Tp = VARIABLE)
	{
		if ((CG.getVariable(myword[nowcount - 1].token)) == -1)
		{
			cout << "error at  " << myword[nowcount - 1].token << " 使用未定义过的变量";
			return ERROR;

		}
		floor++;
		ceshi(floor);
		cout << "标识符 " << myword[nowcount - 1].token << endl;
		int c = scanner();
		floor--;
		if (c == SEMICOLON) {//分号
			ceshi(floor);
			cout << ";" << endl;
			return c;
		}
		else if (c == COMMA) {//逗号
			ceshi(floor);
			cout << "," << endl;
			int d = varAnalyer();
			return d;
		}
		else {
			scanner();
			errorPrimary();
			return ERROR;
		}
	}
	else {
		errorPrimary();
		return ERROR;
	}
}

//语句分析
int GrammerAnalyzer::stateAnalyer() {
	ceshi(floor);
	cout << "语句" << endl;
	floor++;
	int a;
	a = scanner();
	//复合语句
	if (a == BEGIN) {
		ceshi(floor);
		cout << "复合语句" << endl;
		floor++;
		if (whileflag>0)
			beginflag = 1;
		ceshi(floor);
		cout << "begin" << endl;
		int b = complexAnalyer();
		floor--;
		if (b != ERROR)
		{

			cout << "COMPLEX SUCCESS" << endl;
			return b;
		}
		else
		{
			cout << "COMPLEX ERROR" << endl;
		}
	}
	//赋值语句
	else if (a == VARIABLE) {
		ifflag = 0;
		ceshi(floor);
		cout << "赋值语句" << endl;
		//if (whileflag ==0)
		//l++;

		floor++;
		code[t].statement += "l" + to_string(l) + "\n";
		int b = variableAnalyer();
		floor--;
		if (b != ERROR)
		{

			cout << "VARIABLE SUCCESS" << endl;
			return b;
		}
		else
		{
			cout << "VARIABLE ERROR" << endl;
		}
	}
	//条件语句
	else if (a == IF) {
		ceshi(floor);
		cout << "条件语句" << endl;
		ifflag = 1;
		l++;
		floor++;
		int b = conditionAnalyer();
		floor--;
		if (b != ERROR)
		{
			cout << "CONDITION SUCCESS" << endl;
			return b;

		}
		else
		{
			cout << "CONDITION ERROR" << endl;
		}
	}
	//循环语句
	else if (a == WHILE) {
		ceshi(floor);
		l++;
		whileflag = l;
		cout << "循环语句" << endl;
		floor++;
		int b = loopAnalyer();
		l++;
		floor--;
		if (b != ERROR)
		{

			cout << "LOOP SUCCESS" << endl;
			return b;
		}
		else
		{
			cout << "LOOP ERROR" << endl;
		}
	}
	else if (a == ERROR)
	{
		return ERROR;
	}
	else if (a == END)
	{
		return a;
	}
	else
	{
		errorPrimary();
		return ERROR;
	}
}

//赋值语句
int GrammerAnalyzer::variableAnalyer() {
	//cout << "IN VARIABLEANALYER   " << nowcount << endl;
	code[t].statement += myword[nowcount - 1].token;
	ceshi(floor);
	//codeflag++;
	if ((CG.getVariable(myword[nowcount - 1].token)) == -1)
	{
		cout << "error at  " << myword[nowcount - 1].token << " 使用未定义过的变量";
		return ERROR;

	}
	cout << "标识符 " << myword[nowcount - 1].token << endl;

	if (CG.getConst(myword[nowcount - 1].token) == true)
	{
		cout << "error at " << myword[nowcount - 1].token << "Const 类型数据不能赋值" << endl;
		return ERROR;
	}
	int a = scanner();
	if (a == EQUALITY) {
		ceshi(floor);
		cout << "=" << endl;
		code[t].statement += "=";
		code[t].statement += ("s" + to_string(snum));
		code[t].statement += ";";
		ceshi(floor);
		cout << "表达式" << endl;

		floor++;
		int m = expressionAnalyer();//表达式
		floor--;

		if (m == ERROR)
		{
			return ERROR;
		}
		int b = scanner();
		if (b == SEMICOLON)//识别到分号结束
		{

			code[t].statement += ";";
			if (whileflag > 0 && beginflag == 0)  //while语句是单语句结束，
			{
				code[t].statement += "goto l" + to_string(whileflag);
				whileflag = 0;
				//l++;
			}
			t++;
			ceshi(floor);
			cout << ";" << endl;

			return b;
		}
		else
		{
			errorPrimary();
			return ERROR;
		}
	}
	else
	{
		errorPrimary();
		return ERROR;
	}

}

//表达式分析
int GrammerAnalyzer::expressionAnalyer() {
	//cout << "IN EXPRESSION   " << nowcount << endl;

	if (myword[nowcount - 1].syn == EQUALITY)
	{
		codeflag = 0;
		code[t].statement += "s" + to_string(snum++) + "=";
	}
	int a = scanner();
	if ((a == PLUS) || (a == MINUS)) {
		if (a == PLUS)
			code[t].statement += "+";
		else
			code[t].statement += "-";
		ceshi(floor);
		cout << "+ | -" << endl;
		ceshi(floor);
		cout << "项" << endl;
		floor++;
		int m = napeAnalyer();
		floor--;
		//cout << "REUTRN EXPRESSION   " << nowcount << endl;
		if (m == ERROR)
		{
			return ERROR;
		}
		int b = scanner();
		if ((b == PLUS) || (b == MINUS))
		{
			ceshi(floor);
			if (b == PLUS)
				code[t].statement += "+";
			else
				code[t].statement += "-";
			cout << "+ | -" << endl;
			int c = expressionAnalyer();
			return c;
		}
		else
		{
			nowcount--;
			return m;
		}
	}
	else
	{
		nowcount--;
		ceshi(floor);
		cout << "项" << endl;
		floor++;
		int b = napeAnalyer();
		floor--;
		if (b == ERROR)
		{
			return ERROR;
		}
		b = scanner();
		if ((b == PLUS) || (b == MINUS))
		{
			ceshi(floor);
			if (b == PLUS)
			{
				//if (bracketflag>0)
				//jfoierjo
				code[t].statement += "+";
			}
			else
			{
				code[t].statement += "-";
			}
			cout << "+ | -" << endl;
			int c = expressionAnalyer();
			return c;
		}
		else
		{
			nowcount--;
			return b;
		}
	}

}

//项判断
int GrammerAnalyzer::napeAnalyer() {
	//cout << "IN NAPE      " << nowcount << endl;
	ceshi(floor);
	cout << "因子" << endl;
	floor++;
	int a = factorAnalyer();
	floor--;
	//cout << "RETURN NAPE      " << nowcount << endl;
	if (a != ERROR)
	{
		int b = scanner();
		if (b == MULTIPLE || b == DIVISION)
		{
			ceshi(floor);
			cout << "* | /" << endl;
			if (b == MULTIPLE)
				code[t].statement += "*";
			else
				code[t].statement += "/";

			int c = napeAnalyer();
			return c;
		}
		else
		{
			//cout << "RETURN NAPE    1  " << nowcount << endl;
			nowcount--;
			//cout << "RETURN NAPE   2   " << nowcount << endl;
			return a;
		}
	}
	else
	{
		return ERROR;
	}
}

//因子判断
int GrammerAnalyzer::factorAnalyer() {
	int a;
	//cout << "IN factor        " << nowcount << endl;
	a = scanner();
	if (a == VARIABLE) //标识符
	{
		if ((CG.getVariable(myword[nowcount - 1].token)) == -1)
		{
			cout << "error at  " << myword[nowcount - 1].token << " 使用未定义过的变量";
			return ERROR;

		}
		codeflag++;
		ceshi(floor);
		if (codeflag == 2 && myword[nowcount].syn != SEMICOLON)
		{
			if (ifflag == 0)
			{
				code[t].statement += +"s" + to_string(snum) + ";";
				code[t].statement += "s" + to_string(snum++) + "=";
				if (CG.getConstValue(myword[nowcount - 1].token) != "a")
				{
					code[t].statement += "@" + CG.getConstValue(myword[nowcount - 1].token);
				}
				else
					code[t].statement += myword[nowcount - 1].token;
				codeflag = 1;
			}
			else
			{
				codeflag = 0;
				if (CG.getConstValue(myword[nowcount - 1].token) != "a")
				{
					code[t].statement += "@" + CG.getConstValue(myword[nowcount - 1].token) + " ";
				}
				else
					code[t].statement += myword[nowcount - 1].token + " ";
			}

		}
		else
		{
			if (CG.getConstValue(myword[nowcount - 1].token) != "a")
			{
				code[t].statement += "@" + CG.getConstValue(myword[nowcount - 1].token);
			}
			else
				code[t].statement += myword[nowcount - 1].token;
		}

		cout << "标识符 " << myword[nowcount - 1].token << endl;
		return a;
	}
	else if (a == VALUE) //无符号整数
	{
		ceshi(floor);
		if (CG.getConstValue(myword[nowcount - 1].token) != "a")
		{
			code[t].statement += "@" + CG.getConstValue(myword[nowcount - 1].token) + " ";
		}
		else
			code[t].statement += myword[nowcount - 1].token;
		cout << "无符号整数 " << myword[nowcount - 1].token << endl;
		return a;
	}
	else if (a == LEFTBRACKET)
	{
		ceshi(floor);
		bracketflag++;
		code[t].statement += "s" + to_string(snum++) + ";";
		code[t].statement += "s" + to_string(snum - 1) + "=";
		int s1 = snum, s2 = snum - 1;
		//code[t].statement += "s" + to_string(snum);
		cout << "( " << endl;
		int b;
		floor++;
		b = expressionAnalyer();
		floor--;
		if (b == ERROR)
		{
			return ERROR;
		}
		int c = scanner();
		if (c == RIGHTBRACKET)
		{
			bracketflag--;
			ceshi(floor);
			snum++;
			code[t].statement += ";s" + to_string(s1) + "=s" + to_string(s2);
			//code[t].statement += "s" + to_string(snum) ;
			//code[t].statement += ")";
			cout << ")" << endl;
			s1 = s2 = 0;
			return c;
		}
		else
		{
			nowcount--;
			return ERROR;
		}
	}
	else
	{
		//errorPrimary();
		cout << a << endl;
		cout << "this error" << endl;
		return ERROR;
	}
}

//复合语句
int GrammerAnalyzer::complexAnalyer() {
	//cout << "IN COMPLEX" << endl;
	int a = stateAnalyer();
	floor--;
	while (a != END)
	{
		if (a == ERROR)
		{
			break;
		}
		a = stateAnalyer();
		floor--;
	}
	if (a == END)
	{
		if (whileflag != 0 && beginflag == 1)//while语句是复合语句
		{
			beginflag = 0;
			code[t].statement += "goto  l" + to_string(whileflag) + "\n";
			//l++;
		}
		ceshi(floor);
		cout << "end" << endl;
		whileflag = 0;
		return a;
	}
	else
	{
		return ERROR;
	}
}

//条件语句
int GrammerAnalyzer::conditionAnalyer() {
	//cout << "IN CONDITION" << endl;

	code[t].statement += "if  ";
	ceshi(floor);
	cout << "if" << endl;
	ceshi(floor);
	cout << "条件" << endl;
	int a;
	floor++;
	a = termAnalyer();
	floor--;
	if (a != ERROR)
	{
		int b = scanner();
		if (b == THEN)
		{
			ifflag = 1;
			ceshi(floor);
			cout << "then" << endl;
			code[t].statement += "goto  l" + to_string(l) + "\n";
			//code[t].statement += "then ";
			int c = stateAnalyer();
			floor--;
			if (c != ERROR)
			{
				int d = scanner();
				l++;
				if (d == ELSE)
				{
					ceshi(floor);

					code[t].statement += "  l" + to_string(l) + "\n";
					cout << "else" << endl;
					int e = stateAnalyer();
					floor--;
					return e;
				}
				else
				{
					nowcount--;
					return 1;
				}
			}
			else
			{
				return ERROR;
			}
		}
		else
		{
			errorPrimary();
			return ERROR;
		}
	}
}

//条件分析
int GrammerAnalyzer::termAnalyer() {
	//cout << "IN TERM" << endl;
	ceshi(floor);
	cout << "表达式" << endl;
	floor++;
	int a = expressionAnalyer();
	floor--;
	if (a != ERROR)
	{
		int b = scanner();
		if (b == COLONEQUALITY || b == MORETHAN || b == LESSEQUALITY || b == LESSTHAN || b == NOEQUALITY || MOREEQUALITY)
		{
			ceshi(floor);
			//code[t].statement += "s" + to_string(snum) + "=";
			if (CG.getConstValue(myword[nowcount - 1].token) != "a")
			{
				code[t].statement += "  @" + CG.getConstValue(myword[nowcount - 1].token) + "  ";
			}
			else
				code[t].statement += "  " + myword[nowcount - 1].token + "  ";
			cout << "< | > | == " << endl;
			ceshi(floor);
			cout << "表达式" << endl;
			floor++;
			int c = expressionAnalyer();
			floor--;
			return c;
		}
		else
		{
			return b;
		}
	}
	else
	{
		return ERROR;
	}
}

//当循环语句
int GrammerAnalyzer::loopAnalyer() {
	//cout << "IN LOOP" << endl;
	code[t].statement += "while  ";
	ceshi(floor);
	cout << "while" << endl;
	ceshi(floor);
	cout << "条件" << endl;
	floor++;
	int a = termAnalyer();
	floor--;
	if (a != ERROR)
	{
		int b = scanner();
		if (b == DO)
		{
			ceshi(floor);
			cout << "do" << endl;
			code[t].statement += "goto  l" + to_string(l) + "\n";
			int c = stateAnalyer();
			floor--;
			if (whileflag != 0)
				code[t].statement += "goto  l" + to_string(whileflag) + "\n";
			if (c == ERROR)
				return ERROR;
			else
				return 1;
		}
		else
		{
			errorPrimary();
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}

void GrammerAnalyzer::errorPrimary() {
	if (nowcount >= count - 1)
	{
		int a = nowcount - 1;
		cout << "ERROR AT " << myword[a].token << endl;
	}
	else
	{
		cout << "ERROR BEFOR " << myword[nowcount].token << endl;
	}
}