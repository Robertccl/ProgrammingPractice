#include"my.h"
#include<fstream>
#include"zjdm.h"




void CodeGeneration::initMyCode()
{
	if (myword[read].syn == CONST || myword[read].syn == VAR || myword[read].syn == COMMA)
	{
		read++;
		if (myword[read].syn == CONST || myword[read].syn == VAR)
			flag = myword[read].syn;
		return initMyCode();
	}
	else if (myword[read].syn == VARIABLE && myword[read - 1].syn == CONST)
	{
		while (myword[read].syn != SEMICOLON)
		{
			if (myword[read].syn == EQUALITY || myword[read].syn == COMMA)
			{
				if (myword[read].syn == COMMA)
					write++;
				read++;
			}
			else if (myword[read].syn == VALUE)
			{
				myCode[write].value = myword[read].token;
				read++;
			}
			else if (myword[read].syn == VARIABLE)
			{
				myCode[write].type = CONST;
				if (getVariable(myword[read].token) == -1)
					myCode[write].variable = myword[read].token;
				else
				{
					cout << "error near " << myword[read].token << "  变量重复定义！" << endl;
					return;
				}
				read++;
			}
		}
		write++;
		read++;
		return initMyCode();
	}
	else if (myword[read].syn == VARIABLE)
	{
		myCode[write].type = VARIABLE;
		if (getVariable(myword[read].token) == -1)
			myCode[write].variable = myword[read].token;
		else
		{
			cout << "error near " << myword[read].token << "变量重复定义！" << endl;
			return;
		}

		myCode[write].value = "0";
		write++;
		read++;
		return initMyCode();
	}
	else if (myword[read].syn == COLON)
		return;
}

int CodeGeneration::getVariable(string key)
{
	int temp = -1;
	for (int i = 0; i < write; i++)
	{
		if (myCode[i].variable == key)
			temp = myCode[i].type;
	}
	return temp;
}

string CodeGeneration::getConstValue(string key)
{
	string temp = "a";
	for (int i = 0; i < write; i++)
	{
		if (myCode[i].variable == key && myCode[i].type == CONST)
			temp = myCode[i].value;
	}
	return temp;
}

bool CodeGeneration::getConst(string key)
{

	for (int i = 0; i < write; i++)
	{
		if (myCode[i].variable == key && myCode[i].type == CONST)
			return true;
	}
	return false;
}

void CodeGeneration::print()
{
	for (int i = 0; i < write; i++)
	{
		cout << myCode[i].type << "   " << myCode[i].variable << "   " << myCode[i].value << endl;
	}
}