//
// Created by rober on 18-1-18.
//
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

bool IsPrimer(int n)
{
    int m=sqrt(n);
    for(int i=2; i<=m; i++)
        if(n%i==0)
            return false;
    return true;
}
/*
 * 最后一行最后一个数字后面不能有空格
 *
 */

//int main()
//{
//
//    int n,m;
//    int i=2,k=0, flag=0;
//
//    cin>>n>>m;
//    while(true)
//    {
//        if(IsPrimer(i))
//        {
//            k++;
//            if(k>=n && k<=m)
//            {
//                flag++;
//                if(flag<10 && k!=m)
//                    cout<<i<<" ";
//                else
//                {
//                    cout<<i<<endl;
//                    flag=0;
//                }
//            }
//            if(k>m)
//                break;
//        }
//        i++;
//    }
//    return 0;
//}
