#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	char a[15], b[15];
	int a1, b1;
	int suma=0, sumb=0;
	scanf("%s%d%s%d", a, &a1, b, &b1);
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]-'0'==a1)
			suma=suma*10+a1;
		i++;
	}
	i=0;
	while(b[i]!='\0')
	{
		if(b[i]-'0'==b1)
			sumb=sumb*10+b1;
		i++;
	}
	cout<<suma+sumb<<endl;
	return 0;
}
