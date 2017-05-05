////
//// Created by chen on 17-4-17.
////
//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//typedef struct Node
//{
//    int leftChild;
//    int data;
//    int rightChild;
//}treeNode;
//
//vector<treeNode> tree(20);
//vector<int> leaves(20, -1);
//
//const static int Null = -1;
//const static int ERRORTREE = -11;
//
//int Read1(vector<treeNode> &tempV, int num);
//void PrintLeaves(int root, int num);
//
//
//int main()
//{
//    int num;
//    cin>>num;
//
//    int root = Read1(tree, num);
//    if(root != ERRORTREE)
//        PrintLeaves(root, num);
//
//    return 0;
//}
//
//
//int Read1(vector<treeNode> &tempV, int num)
//{
//
//    string temp;
//    for(int i=0; i<num; i++)
//    {
//        tempV[i].data=i;
//        cin>>temp;
//        if(temp == "-")
//            tempV[i].leftChild=Null;
//        else
//            tempV[i].leftChild=stoi(temp);
//        temp="";
//        cin>>temp;
//        if(temp == "-")
//            tempV[i].rightChild=Null;
//        else
//            tempV[i].rightChild=stoi(temp);
//    }
//    vector<bool> check(num+2, true);
//    for(int i=0; i<num; i++)
//    {
//        if(tempV[i].leftChild != Null)
//            check[tempV[i].leftChild]=false;
//        if(tempV[i].rightChild != Null)
//            check[tempV[i].rightChild]=false;
//    }
//    for(int i=0; i<num; i++)
//    {
//        if(check[i])
//        {
//            tempV[num].data='r';
//            tempV[num].leftChild=i;
//            tempV[num].rightChild=i;
//            return i;
//        }
//    }
//    return ERRORTREE;
//}
//
//void PrintLeaves(int root, int num)
//{
//    vector<int> v;
//    queue<int> travel;
//    int n=num;
//    int k=root;
//    travel.push(root);
//    while(!travel.empty())
//    {
//        k=travel.front();
//
//        if(tree[k].leftChild==Null && tree[k].rightChild==Null)
//        {
//            v.push_back(k);
//            travel.pop();
//        }
//        else if(tree[k].leftChild!=Null && tree[k].rightChild==Null)
//        {
//            travel.pop();
//            travel.push(tree[k].leftChild);
//        }
//        else if(tree[k].leftChild==Null && tree[k].rightChild!=Null)
//        {
//            travel.pop();
//            travel.push(tree[k].rightChild);
//        }
//        else if(tree[k].leftChild!=Null && tree[k].rightChild!=Null)
//        {
//            travel.pop();
//            travel.push(tree[k].leftChild);
//            travel.push(tree[k].rightChild);
//        }
//
//    }
//
//    for(int i=0; i<v.size()-1; i++)
//    {
//        cout<<v[i]<<" ";
//    }
//    cout<<v[v.size()-1]<<endl;
//
//}
//
////bool PrintLeaves(int root)
////{
////    //queue<int> travel;
////    if(tree[root].rightChild==Null && tree[root].leftChild==Null)
////    {
////        leaves.push_back(root);
////        return true;
////    }
////    else if(tree[root].rightChild==Null && tree[root].leftChild!=Null)
////    {
////        return PrintLeaves(tree[root].leftChild);
////    }
////    else if(tree[root].rightChild!=Null && tree[root].leftChild==Null)
////    {
////        return PrintLeaves(tree[root].rightChild);
////    }
////    else if(tree[root].rightChild!=Null && tree[root].leftChild!=Null)
////    {
////        return (PrintLeaves(tree[root].rightChild)&&PrintLeaves(tree[root].leftChild));
////    }
////
////}
//
//
