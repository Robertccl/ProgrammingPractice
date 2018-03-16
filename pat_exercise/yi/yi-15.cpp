#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct node
{
	char num[10];
	int de;
	int cai;
}node15;

bool Cmp(node15 a, node15 b);

int main()
{
	int N, L, H;
	vector<node15> v1, v2, v3, v4;
	int count=0;
	scanf("%d%d%d",&N, &L, &H);
	node15 no;
	for(int i=0; i<N; i++)
	{
		scanf("%s%d%d", no.num, &no.de, &no.cai);
		if(no.de>=L && no.cai>=L)
		{
			count++;
			if(no.de>=H)
			{
				if(no.cai>=H)
					v1.push_back(no);
				else
					v2.push_back(no);
			}
			else if(no.de>=no.cai)
			{
				v3.push_back(no);
			}
			else
				v4.push_back(no);	
		}
		
	}
	sort(v1.begin(), v1.end(), Cmp);
	sort(v2.begin(), v2.end(), Cmp);
	sort(v3.begin(), v3.end(), Cmp);
	sort(v4.begin(), v4.end(), Cmp);
	printf("%d\n", count);	
	vector<node15>::iterator it;

	for(it=v1.begin(); it!=v1.end(); it++)
	{
		printf("%s %d %d\n", it->num, it->de, it->cai);
	}	
	for(it=v2.begin(); it!=v2.end(); it++)
	{
		printf("%s %d %d\n", it->num, it->de, it->cai);
	}
	for(it=v3.begin(); it!=v3.end(); it++)
	{
		printf("%s %d %d\n", it->num, it->de, it->cai);
	}
	for(it=v4.begin(); it!=v4.end(); it++)
	{
		printf("%s %d %d\n", it->num, it->de, it->cai);
	}
	return 0;
}

bool Cmp(node15 a, node15 b)
{
	if((a.cai+a.de)!=(b.cai+b.de))
		return (a.cai+a.de)>(b.cai+b.de);
	else
	{
		if(a.de!=b.de)
			return a.de>b.de;
		else 
			return strcmp(a.num, b.num)<0;
	 } 
		
}
