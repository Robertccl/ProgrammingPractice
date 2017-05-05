////
//// Created by chen on 17-4-21.
////
//
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <utility>

using namespace std;

typedef struct Node
{
    struct Node* leftChild;
    int data;
    struct Node* rightChild;
}treeNode;
typedef treeNode* tree;


tree BuildTree(int num, queue<string> vtree);
void travel_last(tree root);


//int main()
//{
//    int num;
//    cin>>num;
//    queue<string> vtree;
//    string temp1;
//    int i=0;
//    while(i<num)
//    {
//        cin>>temp1;
//        vtree.push(temp1);
//        if(temp1 != "Push" && temp1 != "Pop")
//            i++;
//    }
//
//
//    tree root=BuildTree(num, vtree);
//    travel_last(root);
//
//    return 0;
//}
//
tree BuildTree(int num, queue<string> vtree)
{
    stack<tree> pretravelstack;
    tree newNode, ptemp;
    tree root=new treeNode;
    root->leftChild=NULL;
    root->rightChild=NULL;

//    bool flag=true;  //flag为真表示上一次操作为push，否则为pop

    if(vtree.front() == "Push")
    {
        vtree.pop();
        root->data=stoi(vtree.front());
        vtree.pop();
        pretravelstack.push(root);
    }
    ptemp=root;
    while(!vtree.empty())
    {
        newNode = new treeNode;
        newNode->leftChild=NULL;
        newNode->rightChild=NULL;
        if(vtree.front() == "Push")
        {
            vtree.pop();
            newNode->data = stoi(vtree.front());
            vtree.pop();

            if(ptemp->leftChild == NULL)
            {
                ptemp->leftChild = newNode;
            }
            else if(ptemp->rightChild == NULL)
            {
                ptemp->rightChild = newNode;
            }
            pretravelstack.push(newNode);
            ptemp=newNode;
        }
        else if(vtree.front() == "Pop")
        {
            ptemp = pretravelstack.top();
            pretravelstack.pop();
            vtree.pop();
        }

    }
    return root;

}

/*
 * 树的後序遍历非递归实现
 *
 */
void travel_last(tree root)
{
    stack<tree> lasttravel;
    lasttravel.push(root);
    tree ptemp=NULL;
    while(!lasttravel.empty())
    {
        ptemp=lasttravel.top();
        if(ptemp->leftChild !=NULL)
        {
            lasttravel.push(ptemp->leftChild);
            ptemp->leftChild=NULL;
        }
        else if(ptemp->rightChild !=NULL)
        {
            lasttravel.push(ptemp->rightChild);
            ptemp->rightChild=NULL;
        }
        else if(lasttravel.top()!=root)
        {
            cout<<ptemp->data<<" ";
            delete ptemp;
            lasttravel.pop();
        }
        else
            lasttravel.pop();
    }

    if(root->rightChild==NULL&&root->leftChild==NULL)
    cout<<root->data;
    delete root;


}


/*
 * 树的後序遍历递归实现
 *
 */
//void travel_last(tree root)
//{
//    if(root == NULL)
//        return;
//    else
//    {
//        travel_last(root->leftChild);
//
//        travel_last(root->rightChild);
//
//        cout<<root->data<<" ";
//    }
//
//
//
//}

