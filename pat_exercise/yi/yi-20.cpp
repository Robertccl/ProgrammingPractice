#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct node
{
	int ku;
	int price;
	float djia;
}node20;

bool cmp(node20 a, node20 b)
{
	return a.djia>b.djia; 
}

int main()
{
	int n=0, sum=0;
	float allprice=0;
	node20 no[1024];
	memset(no, '\0', sizeof(node20)*1024);
	float djia[1024]={0.0};
	scanf("%d%d", &n, &sum);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &no[i].ku);
	}
	getchar();
	for(int i=0; i<n; i++)
	{
		scanf("%d", &no[i].price);
		no[i].djia=no[i].price/(float)no[i].ku;
	}
	sort(no, no+n, cmp);
	int j=0;
	while(sum && j<n)
	{
		if(no[j].ku>=sum)
		{
			allprice +=sum/(float)no[j].ku * no[j].price;
			sum-=sum;
		}
		else
		{
			allprice += no[j].price;
			sum-=no[j].ku;
		}
		j++;
		
	}
	printf("%.2f\n", allprice);
	return 0;
}
