#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
	{
		if(pre.size()==0 || vin.size()==0)
			return NULL;
		TreeNode* root = new TreeNode(pre[0]);
		
		vector<int> leftPre, leftVin, rightPre, rightVin;
		int k=-1;
		for(int i=0; i<vin.size(); i++)
		{
			if(vin[i] == root->val)
			{
				k=i;
				continue;
			}	
			if(k==-1)
			{
				leftPre.push_back(pre[i+1]);
				leftVin.push_back(vin[i]);
			}
			else
			{
				rightPre.push_back(pre[i]);
				rightVin.push_back(vin[i]);
			}
		}
		
		root->left=reConstructBinaryTree(leftPre, leftVin);
		
		root->right=reConstructBinaryTree(rightPre, rightVin);
		
		return root;
	
	}
    


int main()
{
	int a1[]={1,2,4,7,3,5,6,8};
	int a2[]={4,7,2,1,5,3,8,6};
	
	vector<int> v1, v2;
	
	for(int i=0; i<8; i++)
	{
		v1.push_back(a1[i]);
		v2.push_back(a2[i]);
	}
	
	
	TreeNode* root= reConstructBinaryTree(v1, v2);
	
	cout<<root->val<<"left"<<root->left->val;
	return 0;
}
