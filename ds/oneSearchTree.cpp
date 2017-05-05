//
// Created by chen on 17-4-21.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

typedef struct Node
{
    struct Node* leftChild;
    int data;
    struct Node* rightChild;
    bool flag;   //flag为true表示没有搜索到过
}treeNode;
typedef treeNode* tree;

tree BuildTree(const vector<int> &vdata);
bool JudgeTree(tree root, const vector<int> vtest);
void ResetTree(tree root);
void FreeTree(tree root);

bool Check(tree root, int v);
void InsertTree(tree root, int data);

//int main()
//{
//    int num=0, N=0;
//    int temp;
//    vector<int> vdata, vtest;
//    cin>>num;
//    tree root=NULL;
//    while (num)
//    {
//        cin>>N;
//        for(int i=0; i<num; i++)
//        {
//            cin >> temp;
//            vdata.push_back(temp);
//        }
//        root = BuildTree(vdata);
//        while(N--)
//        {
//            for(int i=0; i<num; i++)
//            {
//                cin>>temp;
//                vtest.push_back(temp);
//            }
//
//            if(JudgeTree(root, vtest))
//                cout<<"Yes"<<endl;
//            else
//                cout<<"No"<<endl;
//
//            ResetTree(root);
//            vtest.clear();
//        }
//        FreeTree(root);
//        vdata.clear();
//        cin>>num;
//        root=NULL;
//    }
//    return 0;
//}

tree BuildTree(const vector<int> &vdata)
{
    tree ptemp=NULL;

    tree root= new treeNode;
    root->leftChild=NULL;
    root->rightChild=NULL;
    root->data=vdata[0];
    root->flag=true;

    for(int i=1; i<vdata.size(); i++)
    {
        InsertTree(root, vdata[i]);
    }
    return root;
}

bool JudgeTree(tree root, const vector<int> vtest)
{
    for(int i=0; i<vtest.size(); i++)
    {
        if (!Check(root, vtest[i]))
            return false;
    }
    return true;
}

void ResetTree(tree root)
{
    if(root->flag == false)
    {
        root->flag=true;
    }
    if(root->leftChild != NULL)
        ResetTree(root->leftChild);
    if(root->rightChild != NULL)
        ResetTree(root->rightChild);
}

void FreeTree(tree root)
{
    if(root->leftChild != NULL)
        FreeTree(root->leftChild);
    if(root->rightChild != NULL)
        FreeTree(root->rightChild);
    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        delete root;
    }
}

void InsertTree(tree root, int data)
{
    tree ptemp=NULL;
    if(root!=NULL)
    {
        if(root->data == -1)
        {
            root->data=data;
        }
        else if(root->data >= data)
        {
            if(root->leftChild == NULL)
            {
                ptemp=new treeNode;
                ptemp->leftChild=NULL;
                ptemp->rightChild=NULL;
                ptemp->data=-1;
                ptemp->flag=true;
                root->leftChild=ptemp;
            }
            InsertTree(root->leftChild, data);
        }
        else if(root->data < data)
        {
            if(root->rightChild == NULL)
            {
                ptemp=new treeNode;
                ptemp->leftChild=NULL;
                ptemp->rightChild=NULL;
                ptemp->data=-1;
                ptemp->flag=true;
                root->rightChild=ptemp;
            }
            InsertTree(root->rightChild, data);
        }
    }
}

bool Check(tree root, int v)
{
    if(!root->flag)
    {
        if(v < root->data)
            return Check(root->leftChild, v);
        else if(v > root->data)
            return Check(root->rightChild, v);
        else
            return false;
    }
    else
    {
        if(v == root->data)
        {
            root->flag = false;
            return true;
        }
        else
            return false;
    }
}


