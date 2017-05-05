//
// Created by chen on 17-4-14.
//
#include <iostream>

using namespace std;

#include "MaxOperator.h"

/*For each test case, output in one line the largest sum,
 * together with the first and the last numbers of the maximum subsequence.
 * The numbers must be separated by one space,
 * but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique,
 * output the one with the smallest indices iii and jjj (as shown by the sample case).
 * If all the KKK numbers are negative, then its maximum sum is defined to be 0,
 * and you are supposed to output the first and the last numbers of the whole sequence.
 *
 *
 * https://pta.patest.cn/pta/test/3512/exam/4/question/58272
 */

int MaxOperator::MaxSubseqSum4(int a[], int N)
{
    de d=new Node;
    d->start=0;
    d->end=0;
    d->maxnum=0;
    int start=0;
    int end=0;
    int thisSum=0, maxSum=0;
    for(int j=0; j<N; j++)
    {
        end++;
        thisSum += a[j];
        if(thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        if(thisSum < 0)
        {
            thisSum=0;
            start = j+1;
            end = j+1;
        }

        if(maxSum > d->maxnum)
        {
            d->maxnum=maxSum;
            d->start=start;
            d->end=end-1;
        }

    }
    if(d->maxnum == 0)
    {
        cout<<d->maxnum<<" "<<a[0]<<" "<<a[N-1]<<endl;
    }
    else
        cout<<d->maxnum<<" "<<a[d->start]<<" "<<a[d->end]<<endl;

    return maxSum;

}
