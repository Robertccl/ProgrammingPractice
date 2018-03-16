#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a=0, b=0, d=0;
	scanf("%d%d%d", &a, &b, &d);
	int arr[100]={0};
	int k=0;
	int sum=a+b;
	
	if(!sum)
	printf("0");
	else
	{
			while(sum)
		{
			arr[k++]=sum%d;
			sum/=d;
		}	
		for(int i=k-1; i>=0; i--)
		printf("%d", arr[i]); 
	}

	return 0;
}
