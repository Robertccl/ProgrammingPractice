//
// Created by chen on 17-4-14.
//

#ifndef DS_MAXOPERATOR_H
#define DS_MAXOPERATOR_H

typedef struct Node *PtrToNode;
struct Node{
    int maxnum;
    int start;
    int end;
};
typedef PtrToNode de;

class MaxOperator {
public:
    int MaxSubseqSum4(int a[], int N);

};


#endif //DS_MAXOPERATOR_H
