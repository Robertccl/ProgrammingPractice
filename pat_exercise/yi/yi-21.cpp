#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char arr[1024];
	int a[10]={0};
	gets(arr);
	int i=0;
	int k=0;
	while(arr[i]!='\0')
	{
		k=arr[i]-'0';
		a[k]++;
		i++;
	}
	for(int i=0; i<10; i++)
	{
		if(a[i]!=0)
		{
			printf("%d:%d\n", i, a[i]);
		}
	}
	return 0;
}
