#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
        
    }

    int pop() {
    	while(!stack1.empty())
    	{
    		
    		stack2.push(stack1.top());
    		stack1.pop();
		}
		int tt = stack2.top();
		stack2.pop();
        while(!stack2.empty())
    	{
    		stack1.push(stack2.top());
    		stack2.pop();
		}
		return tt;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
	Solution s;
	for(int i=0; i<5; i++)
		s.push(i);
		
	for(int i=0; i<2; i++)
	{
		//s.pop();
		cout<<s.pop()<<endl;
	}
	

	return 0;
}
