#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void numtochar(int a, char *arr)
{
	int k=4;
	for(int i=0; i<4; i++)
	{
		arr[k--]=a%10+'0';
		a/=10;
	}
}

int chartonum(char arr[])
{
	int res=0;
	for(int i=4; i>0; i--)
	{
		res*=10;
		res+=arr[i]-'0';
	}
	return res;
}

bool cmp(char a, char b)
{
	return a>b;
}

int main()
{
	int a=0;
	char arr[5]={'0'};
	int min,max;
	scanf("%d", &a);
	if(a%1111==0)
		printf("%04d - %04d = 0000\n", a, a);
	else 
		while(true)
		{
			numtochar(a, arr);
			sort(arr+1, arr+5);
			max=chartonum(arr);
			sort(arr+1, arr+5, cmp);
			min=chartonum(arr);
			a=max-min;
			printf("%04d - %04d = %04d\n", max, min, a);
			if(a==6174)
				break;
		}
	
	return 0;
}
