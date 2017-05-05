//
// Created by chen on 17-4-16.
//

#include<iostream>
#include <string>
#include <vector>

using namespace std;


typedef struct Node
{
    int leftChild;
    char data;
    int rightChild;
}treeNode;

vector<treeNode> tree1(20), tree2(20);
const static int ERRORTREE =-11;
const static int Null = -1;

int Read(vector<treeNode> &tempV);
bool Isomorphism(int root1, int root2);

//int main()
//{
//
//    int root1 = Read(tree1);
//    int root2 = Read(tree2);
//    if(root1!=ERRORTREE && root2!=ERRORTREE)
//    {
//        if(Isomorphism(root1, root2))
//            cout<<"Yes"<<endl;
//        else
//            cout<<"No"<<endl;
//
//    }
//    else
//        cout<<"Yes"<<endl;
//
//    return 0;
//}


int Read(vector<treeNode> &tempV)
{
    int num=0;
    cin>>num;
    string temp;
    for(int i=0; i<num; i++)
    {
        cin>>tempV[i].data;
        cin>>temp;
        if(temp == "-")
            tempV[i].leftChild=Null;
        else
            tempV[i].leftChild=stoi(temp);
        temp="";
        cin>>temp;
        if(temp == "-")
            tempV[i].rightChild=Null;
        else
            tempV[i].rightChild=stoi(temp);

    }
    temp="";

    vector<bool> check(num+2, true);
    for(int i=0; i<num; i++)
    {
        if(tempV[i].leftChild != Null)
            check[tempV[i].leftChild]=false;
        if(tempV[i].rightChild != Null)
            check[tempV[i].rightChild]=false;
    }
    for(int i=0; i<num; i++)
    {
        if(check[i])
        {
            tempV[num].data='r';
            tempV[num].leftChild=i;
            tempV[num].rightChild=i;
            return i;
        }
    }
    return ERRORTREE;
}

bool Isomorphism(int root1, int root2)
{

    if(root1 == Null && root2 == Null)
    {
        return true;
    }
    else if(tree1[root1].data != tree2[root2].data)
    {
        return false;
    }
    else if((root1==Null && root2!=Null) || (root1!=Null && root2==Null))
    {
        return false;
    }
    else if(tree1[root1].leftChild==Null && tree2[root2].leftChild==Null)
    {
        return Isomorphism(tree1[root1].rightChild, tree2[root2].rightChild);
    }
    else if(tree1[root1].leftChild!=Null && tree2[root2].leftChild!=Null
            && tree1[tree1[root1].leftChild].data == tree2[tree2[root2].leftChild].data)
    {
        return (Isomorphism(tree1[root1].leftChild, tree2[root2].leftChild) &&
                Isomorphism(tree1[root1].rightChild, tree2[root2].rightChild));

    }
    else
    {
        return (Isomorphism(tree1[root1].leftChild, tree2[root2].rightChild) &&
                Isomorphism(tree1[root1].rightChild, tree2[root2].leftChild));
    }

}

