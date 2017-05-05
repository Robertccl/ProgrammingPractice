#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

using namespace std;


List MyList::Read()
{
	List header=NULL, p=NULL,p1=NULL;
	int num=0, a=0, b=0;
	cin>>num;

	header=new Node;
	header->xishu=num;
	header->zhishu=-1;
	header->Next=NULL;
	p1=p=header;
	for(int i=0; i<num; i++)
	{
		cin>>a>>b;
		p1=new Node;
		p1->xishu=a;
		p1->zhishu=b;
		p1->Next=NULL;
		p->Next=p1;
		p=p->Next;
	}
	return header;

}

void MyList::Print(List L)
{
	List header = L, p=L->Next;
	//int num=header->xishu;
	//cout<<num<<" ";

	while(p->Next!=NULL)
	{
		cout<<p->xishu<<" "<<p->zhishu<<" ";
		p=p->Next;
	}
	cout<<p->xishu<<" "<<p->zhishu<<endl;
}
/*
 *多项式乘法
 *
 */
List MyList::multList( List L1, List L2 )
{
	List p1=L1->Next, p2= L2->Next;
	List head = new Node;
	head->Next=NULL;
	head->zhishu=-1;
	bool flag=true;

	List p=head, pnew, plast;

	while(p1!=NULL)
	{
        p2=L2->Next;
		while(p2!=NULL)
		{
			pnew = new Node;
			pnew->Next=NULL;
			pnew->xishu = p1->xishu * p2->xishu;
			pnew->zhishu=p1->zhishu + p2->zhishu;

			insert(pnew, head);

			p2=p2->Next;
		}
		p1=p1->Next;
	}
    return head;

}

/*
 * 多项式加法
 *
 */
List MyList::andList( List L1, List L2 )
{
	List head=new Node;
	List p=head, p1=L1->Next, p2=L2->Next, pnew;
    int num=0;
	while(p1!=NULL && p2!=NULL)
	{
		pnew = new Node;
		if(p1->zhishu == p2->zhishu)
		{
			pnew->zhishu=p1->zhishu;
			pnew->xishu=p1->xishu+p2->xishu;
			pnew->Next=NULL;

            if(pnew->xishu == 0)
            {
                delete pnew;
                num--;
            }
            else
            {
                p->Next=pnew;
                p=p->Next;
                p1=p1->Next;
                p2=p2->Next;
                num++;
            }
		}
		else if(p1->zhishu > p2->zhishu)
		{
			pnew->xishu=p1->xishu;
			pnew->zhishu=p1->zhishu;
			pnew->Next=NULL;

			p->Next=pnew;
			p=p->Next;
			p1=p1->Next;
			num++;

		}
		else if(p1->zhishu < p2->zhishu)
		{
			pnew->xishu=p2->xishu;
			pnew->zhishu=p2->zhishu;
			pnew->Next=NULL;

			p->Next=pnew;
			p=p->Next;
			p2=p2->Next;
			num++;
		}
	}
    if(p1 != NULL)
    {
        p->Next=p1;
    }
    else if(p2 != NULL)
    {
        p->Next=p2;
    }
//    while(p1 != NULL || p2 != NULL)
//    {
//        num++;
//        if(p1 != NULL)
//            p1=p1->Next;
//        else
//            p2=p2->Next;
//    }

	head->xishu=num;
	head->zhishu=-1;

	 return head;

}
void MyList::insert(List newNode, List L)
{
    bool flag=true;
	List head=L, plast=NULL, p=NULL;
	if(head->Next==NULL)
	{
		head->Next=newNode;
        flag=false;
	}
	else
	{
		plast=head;
		p=head->Next;
	}
	while(p!=NULL)
	{
		if(p->zhishu == newNode->zhishu)
		{

			p->xishu += newNode->xishu;
            if(p->xishu == 0)
            {
                plast->Next=p->Next;
            }
            //delete p;
			p=NULL;
            flag=false;
		}
		else if(p->zhishu < newNode->zhishu)
		{
			plast->Next=newNode;
			newNode->Next=p;
			p=NULL;
            flag=false;
		}
		else if(p->zhishu > newNode->zhishu)
		{
            plast = plast->Next;
			p=p->Next;
		}
	}
    if(flag)
        plast->Next=newNode;

}

void MyList::deleteList( List L )
{
	List p=L, p1=L;
	while(p!=NULL)
	{
		p1=p;
		p=p->Next;
		cout<<p1->xishu<<endl;
		delete p1;

	}

}

/*
 *  两个有序链表合并
 *  与前面的链表节点不太一样， 需要修改一些东西
 *
 */

List MyList::Merge(List L1, List L2 )
{
    if(L1->Next == NULL)
    {
        return L2;
    }
    if(L2->Next == NULL)
    {
        return L1;
    }

    List listn;
    listn = (List)malloc(sizeof(struct Node));

    List p1,p2,p;
    p1=L1->Next;
    p2=L2->Next;
    p=listn;

//    while(p1!=NULL && p2!=NULL)
//    {
//        if (p1->Data > p2->Data)
//        {
//            p->Next = p2;
//            p2 = p2->Next;
//        }
//        else
//        {
//            p->Next = p1;
//            p1 = p1->Next;
//        }
//        p=p->Next;
//    }
    if(p1!=NULL)
    {
        p->Next=p1;
    }
    else if(p2!=NULL)
    {
        p->Next=p2;
    }

    L1->Next=NULL;
    L2->Next=NULL;

    return listn;
}

