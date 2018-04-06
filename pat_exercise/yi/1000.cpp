#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath> 
using namespace std;

char shu[20]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
              'A', 'B','C', 'D', 'E', 'F', '\0', '\0', '\0', '\0'};

void tento(int data, int b)
{
	char arr[50];
	int temp=0;
	int k=0;
	while(data)
	{
		temp=data%b;
		arr[k]=shu[temp];
		data/=b;
		k++;
	}
	for(int i=k-1; i>=0; i--)
	{
		printf("%c" ,arr[i]);
	}
	printf("\n");
}

long long toten(char data[], int b)
{
	long long w=1;
	int l=strlen(data)-1;
	long long sum=0;
	for(int i=l; i>=0; i--)
	{
		if(data[i]>='0'&&data[i]<='9')
			sum+=(data[i]-'0') * w;
		else
			sum+=(data[i]-'A'+10) * w;
		w*=b;
	}
	return sum;
}

int main()
{
	int b=0;
	long long s1=0,s2=0, s=0;
	char a1[50]={'0'}, a2[50]={'0'};
	while(scanf("%d", &b)!=EOF)
	{
		if(b==10)
		{
			scanf("%d%d", &s1, &s2);
			s=s1+s2;
			printf("%d\n", s);
		}
		else
		{
			scanf("%s%s", a1, a2);
			s1=toten(a1, b);
			s2=toten(a2, b);
			s=s1+s2;
			tento(s, b);
		}
	}
	return 0;
}

