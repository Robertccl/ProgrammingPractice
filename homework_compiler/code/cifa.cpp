#include"my.h"
#include"cifa.h"


void LexicalAnalyzer::Init() //�����ַ���ĳ�ʼ �� ������ĳ�ʼ
{
	count = 0;
	Table[0].token = "begin";
	Table[0].syn = BEGIN;

	Table[1].token = "if";
	Table[1].syn = IF;

	Table[2].token = "then";
	Table[2].syn = THEN;

	Table[3].token = "while";
	Table[3].syn = WHILE;

	Table[4].token = "do";
	Table[4].syn = DO;

	Table[5].token = "end";
	Table[5].syn = END;

	Table[6].token = " ";
	Table[6].syn = VARIABLE;

	Table[7].token = " ";
	Table[7].syn = VALUE;

	Table[8].token = "+";
	Table[8].syn = PLUS;

	Table[9].token = "-";
	Table[9].syn = MINUS;

	Table[10].token = "*";
	Table[10].syn = MULTIPLE;

	Table[11].token = "/";
	Table[11].syn = DIVISION;

	Table[12].token = ":";
	Table[12].syn = COLON;

	Table[14].token = "==";
	Table[14].syn = COLONEQUALITY;

	Table[15].token = "<";
	Table[15].syn = LESSTHAN;

	Table[16].token = "<>";
	Table[16].syn = NOEQUALITY;

	Table[17].token = "<=";
	Table[17].syn = LESSEQUALITY;

	Table[18].token = ">";
	Table[18].syn = MORETHAN;

	Table[19].token = ">=";
	Table[19].syn = MOREEQUALITY;

	Table[20].token = "=";
	Table[20].syn = EQUALITY;

	Table[21].token = ";";
	Table[21].syn = SEMICOLON;

	Table[22].token = "(";
	Table[22].syn = LEFTBRACKET;

	Table[23].token = ")";
	Table[23].syn = RIGHTBRACKET;

	Table[24].token = ",";
	Table[24].syn = COMMA;

	Table[25].token = "Const";
	Table[25].syn = CONST;

	Table[26].token = "Var";
	Table[26].syn = VAR;

	Table[27].token = "else";
	Table[27].syn = ELSE;
}

int  LexicalAnalyzer::is_number_or_letter(char ch)  //�ж��ַ�ch�Ƿ�Ϊ��ĸ������
{                                                   //����Ƕ�����һ���򷵻�1�����򷵻�0
	if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57)
		return 1;
	else return 0;
}

int  LexicalAnalyzer::is_allnumber(string cs)
{
	int length, i, flag = 1;
	string number;
	length = cs.length();
	for (i = 0; i<length; i++)
	{
		number = cs.substr(i, 1);
		if (number<"0" || number>"9") { flag = 0; break; }
	}
	return flag;
}

int  LexicalAnalyzer::find_syn(string cs)
{
	int i;
	for (i = 0; i<28; i++)
		if (cs == Table[i].token)
			return Table[i].syn;
		else
			continue;
	if (is_allnumber(cs) == 1)
		return 11;
	else
	{
		if (cs.substr(0, 1)<"0" || cs.substr(0, 1)>"9") return 10;   //�ַ�������ĸ��ͷ �Ǳ�ʶ��

		else return -1;
	}
}

void LexicalAnalyzer::analyzer()
{
	string cs, emptycs;
	char ch, ch2;
	fstream myfile;
	char filename[50] = "f:/a.txt";
	cout << "������Դ�ļ�·����\n";
	cin >> filename;
	myfile.open(filename, ios::in);
	if (myfile.fail())
	{
		cout << "�Բ����Ҳ�������������ļ�" << filename << endl;
	}
	else  //�ļ��򿪳ɹ�
		while (!myfile.eof())
		{
			ch = myfile.get();//һ��һ�����ļ�
			if (cs == emptycs)   //ǰ����ֵ
			{
				if (is_number_or_letter(ch) == 1) cs += ch;

				else if (ch == '<')
				{
					cs += ch;
					ch2 = myfile.get();
					if (ch2 == '>' || ch2 == '=')//�ҵ�<>����<= 
					{
						cs += ch2;
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
					}
					else //����û��ƥ�䵽����һ����<
					{
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
						if (ch2 != ' ')
							cs += ch2;//?


					}
				}
				else if (ch == '>')
				{
					cs += ch;
					ch2 = myfile.get();
					if (ch2 == '=') //����>=
					{
						cs += ch2;
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
					}
					else //����>
					{
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
						if (ch2 != ' ')
							cs += ch2;
					}
				}
				else if (ch == '=')
				{
					cs += ch;
					ch2 = myfile.get();
					if (ch2 == '=') //����:=
					{
						cs += ch2;
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
					}
					else //ֻ����:
					{
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
						if (ch2 != ' ')
							cs += ch2;
					}
				}
				else if (ch == ' ' || ch == '\n')
				{
					continue;

				}
				else
				{
					cs += ch;
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;
				}
			}
			else              //ǰ����ֵ
			{
				if (is_number_or_letter(ch) == 1) cs += ch;  /*�������ַ������֡���ĸ
															 ���������cs��*/
				else if (ch == ' ' || ch == '\n')
				{
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;

				}
				else if (ch == '<')
				{
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;
					cs += ch;
					ch2 = myfile.get();
					if (ch2 == '>' || ch2 == '=')
					{
						cs += ch2;
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
					}
					else
					{
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
						if (ch2 != ' ')
							cs += ch2;


					}
				}
				else if (ch == '>')
				{
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;

					cs += ch;
					ch2 = myfile.get();
					if (ch2 == '=')
					{
						cs += ch2;
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
					}
					else
					{
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
						if (ch2 != ' ')
							cs += ch2;
					}
				}
				else if (ch == '=')
				{
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;

					cs += ch;
					ch2 = myfile.get();
					if (ch2 == '=')
					{
						cs += ch2;
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
					}
					else
					{
						myword[count].token = cs;
						myword[count].syn = find_syn(cs);
						count++;
						cs = emptycs;
						if (ch2 != ' ')
							cs += ch2;
					}
				}
				else           //�����ַ�Ϊ�����ַ�����cs����ֹ
				{
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;
					cs += ch;
					myword[count].token = cs;
					myword[count].syn = find_syn(cs);
					count++;
					cs = emptycs;
				}
			}
		}//���whileѭ��
	//count--;
	myfile.close();
	myfile.clear();

}

void LexicalAnalyzer::print()
{
	int i;
	cout << count << endl;
	for (i = 0; i<count - 1; i++)
		if (myword[i].syn == -1)
			cout << "(" << myword[i].syn << "," << myword[i].token << ")" << "   Error!" << endl;
		else
		{
			cout << i << "(" << myword[i].syn << "," << myword[i].token << ")" << endl;
		}
}
//��ȡ�ֱ���
int LexicalAnalyzer::Getsyn(int nowcount)
{
	if (nowcount <= count)
		return myword[nowcount].syn;
	else
		return -1;
}
