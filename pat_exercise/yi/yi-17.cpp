#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char a[1024];
	int b, i=0, s=0;
	scanf("%s%d", a, &b);
	bool flag=false;
	while(a[i]!='\0')
	{
		s*=10;
		s+=a[i]-'0';
		if(s/b==0)
		{
			if(flag)
				cout<<s/b;
		}
		else
		{
			cout<<s/b;
			flag=true;
		}
		s=s%b;
		i++;	
	}
	if(!flag)
	cout<<0;
	printf(" %d\n", s);
	return 0;
}
