//
// Created by chen on 17-4-21.
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
    int hight;
}treeNode;
typedef treeNode* tree;

tree CreateNode(int temp);

tree Insert(tree T, int temp);

int GetDepth(tree T);

tree SingleLeftRotate(tree T);

tree SingleRightRotate(tree T);

tree DoubleLeftRightRotate(tree T);

tree DoubleRightLeftRotate(tree T);

//int main()
//{
//    int num;
//    int data;
//    tree T=NULL;
//
//    cin>>num;
//    int i =0;
//    while(i<num)
//    {
//        cin>>data;
//        T = Insert(T, data);
//        i++;
//    }
//
//    cout<<T->data<<endl;
//
//
//    return 0;
//}

tree CreateNode(int temp)
{
    tree p = new treeNode;
    p->data = temp;
    p->rightChild=NULL;
    p->leftChild=NULL;
    p->hight = 0;
    return p;
}

tree Insert(tree T, int temp)
{
    if(!T)
    {
        T = CreateNode(temp);
    }
    else if(temp < T->data)
    {
        T->leftChild = Insert(T->leftChild, temp);
        if(GetDepth(T->leftChild) - GetDepth(T->rightChild) == 2)
            if(temp < T->leftChild->data)
                T = SingleLeftRotate(T);
            else
                T = DoubleLeftRightRotate(T);


    }
    else if(temp > T->data)
    {
        T->rightChild = Insert(T->rightChild, temp);
        if(GetDepth(T->leftChild) - GetDepth(T->rightChild) == -2)
            if(temp > T->rightChild->data)
                T = SingleRightRotate(T);
            else
                T = DoubleRightLeftRotate(T);
    }
    T->hight = GetDepth(T);

    return T;
}

int GetDepth(tree T)
{
    if (!T)
    {
        return 0;
    }
    else
    {
        int leftdepth = GetDepth(T->leftChild);//递归计算左孩子的深度
        int rightdepth = GetDepth(T->rightChild);//递归计算右孩子的深度

        if (leftdepth >= rightdepth)
        {
            return leftdepth + 1;
        }
        else
        {
            return rightdepth + 1;
        }
    }
}


tree SingleLeftRotate(tree T)
{
    tree p=T->leftChild;
    T->leftChild = p->rightChild;
    p->rightChild = T;
    T->hight = GetDepth(T);
    p->hight = GetDepth(p);
    return p;
}

tree SingleRightRotate(tree T)
{
    tree p=T->rightChild;
    T->rightChild = p->leftChild;
    p->leftChild = T;
    T->hight = GetDepth(T);
    p->hight = GetDepth(p);
    return p;

}

tree DoubleLeftRightRotate(tree T)
{
    T->leftChild  = SingleRightRotate(T->leftChild);
    return SingleLeftRotate(T);

}

tree DoubleRightLeftRotate(tree T)
{
    T->rightChild = SingleLeftRotate(T->rightChild);
    return SingleRightRotate(T);

}


