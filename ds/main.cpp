//#include <iostream>
//#include <stdio.h>
//
//using namespace std;
//
//typedef int ElementType;
//typedef struct Node *PtrToNode;
//struct Node
//{
//    ElementType address;
//    ElementType data;
//    ElementType nextAdd;
//    PtrToNode   Next;
//};
//typedef PtrToNode List;
//
//List Read();
//void Print(List L);
//
//
//int main()
//{
//
//    List l=Read();
//    Print(l);
//
//
//    return 0;
//}
///*
// * 02-线性结构3 Reversing Linked List   (25分)
// * https://pta.patest.cn/pta/test/3512/exam/4/question/62614
// *反转链表中的子序列
// *
// */
//
//List Read()
//{
//    List header=NULL, p=NULL,p1=NULL, plast=NULL, pafter=NULL;
//    int startAdd=0, length=0, num=0, tempAddr=0, N=0; //add1=0, add2=0, da=0;
//    cin>>startAdd>>length>>num;
//    N=length;
//
//    header=new Node;
//    header->address=-1;
//    header->data=length;
//    header->nextAdd=-1;
//    header->Next=NULL;
//    plast=header;
//    pafter=p=header;
//    struct Node temp[100000];
//    int k=0;
//    for(int i=0; i<length; i++)
//    {
//        cin>>temp[k].address>>temp[k].data>>temp[k].nextAdd;
//        k++;
//    }
//
//    int flag=0;
//    tempAddr=startAdd;
//    while(N>0)
//    {
//        for (int i = 0; i < length; i++)
//        {
//            if (temp[i].address == tempAddr)
//            {
//                p1 = new Node;
//                if (flag < num && flag != -1)
//                {
//                    p1->address = temp[i].address;
//                    p1->data = temp[i].data;
//                    p1->nextAdd = temp[i].nextAdd;
//                    p1->Next = NULL;
//                    plast->Next = p1;
//                    if (p == header)
//                    {
//                        p = p1;
//                        pafter = p1;
//                    }
//                    else
//                    {
//                        //pafter->address=p1->nextAdd;
//                        p1->nextAdd=pafter->address;
//
//                        p1->Next = pafter;
//                        pafter = p1;
//
//                    }
//                    tempAddr = temp[i].nextAdd;
//                    flag++;
//                    i = 0;
//                    N--;
//                }
//                else if (flag == num)
//                {
//                    if (N >= num)
//                    {
//                        plast = p;
//                        p1->address = temp[i].address;
//                        p1->data = temp[i].data;
//                        p1->nextAdd = temp[i].nextAdd;
//                        p1->Next = NULL;
//                        plast->Next = p1;
//                        p1->Next = p;
//                        //p->address=p1->nextAdd;
//                        plast->nextAdd=p1->address;
//                        tempAddr = temp[i].nextAdd;
//                        flag = 1;
//                        i = 0;
//                        N--;
//                    }
//                    else if (N < num)
//                    {
//                        p1->address = temp[i].address;
//                        p1->data = temp[i].data;
//                        p1->nextAdd = temp[i].nextAdd;
//                        p1->Next = NULL;
//                        p->Next = p1;
//                        //p1->address=p->nextAdd;
//                        p->nextAdd=p1->address;
//                        p = p->Next;
//                        tempAddr = temp[i].nextAdd;
//                        flag = -1;
//                        i = 0;
//                        N--;
//                    }
//                }
//                else if (flag == -1)
//                {
//                    p1->address = temp[i].address;
//                    p1->data = temp[i].data;
//                    p1->nextAdd = temp[i].nextAdd;
//                    p1->Next = NULL;
//                    p->Next = p1;
//                    p->nextAdd=p1->address;
//                    p = p->Next;
//                    tempAddr = temp[i].nextAdd;
//                    i = 0;
//                    N--;
//                }
//            }
//        }
//    }
//
//    return header;
//}
//
//void Print(List L)
//{
//    List header = L, p=L->Next;
//
//    while(p->Next!=NULL)
//    {
//        printf("%05d %d %05d\n", p->address, p->data, p->nextAdd);
//
//        p=p->Next;
//    }
//    printf("%05d %d %d", p->address, p->data, -1);
//}
//

