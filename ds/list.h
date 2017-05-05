//
// Created by chen on 17-4-14.
//

#ifndef DS_LIST_H
#define DS_LIST_H

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType xishu;
    ElementType zhishu;
    PtrToNode   Next;
};
typedef PtrToNode List;

class MyList
{

public:
    List Read();
    void Print( List L );

    List Merge( List L1, List L2 );
    List multList( List L1, List L2 );
    List andList( List L1, List L2 );
    void deleteList( List L );
    void insert(List newNode, List L);



private:

};



#endif //DS_LIST_H
