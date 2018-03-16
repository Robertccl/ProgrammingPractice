#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	char a,b;
	int awin[3]={0}, bwin[3]={0}, ping=0;
	scanf("%d", &n);
	getchar();
	for(int i=0; i<n; i++)
	{
		//getchar();
		scanf("%c %c", &a,&b);
		getchar();
		if(a==b)
		ping++;
		else
		{
			if(a=='B')
			{
				if(b=='C')
				awin[0]++;
				if(b=='J')
				bwin[2]++;
			}
			if(a=='C')
			{
				if(b=='B')
				bwin[0]++;
				if(b=='J')
				awin[1]++;
			}
			if(a=='J')
			{
				if(b=='B')
				awin[2]++;
				if(b=='C')
				bwin[1]++;
			}
		}
	}
	cout<<awin[0]+awin[1]+awin[2]<<" "<<ping<<" "<<bwin[0]+bwin[1]+bwin[2]<<endl;
	cout<<bwin[0]+bwin[1]+bwin[2]<<" "<<ping<<" "<<awin[0]+awin[1]+awin[2]<<endl;
	if(awin[0]>=awin[1])
	{
		if(awin[0]>=awin[2])
		a='B';
		else
		a='J';
	}
	else
	{
		if(awin[1]>=awin[2])
		a='C';
		else
		a='J';
	}
	if(bwin[0]>=bwin[1])
	{
		if(bwin[0]>=bwin[2])
		b='B';
		else
		b='J';
	}
	else
	{
		if(bwin[1]>=bwin[2])
		b='C';
		else
		b='J';
	}
	printf("%c %c",a,b);
	return 0;
}
