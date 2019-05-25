#include <iostream>

using namespace std;

int Fibonacci(int n) 
{
	int i=0,j=1;
	
	while(--n)
	{
		j+=i;
		i=j-i;
	}
	return j;

}


int main()
{
	cout<<Fibonacci(35);
	return 0;
}
