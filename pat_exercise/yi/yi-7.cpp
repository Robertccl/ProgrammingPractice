//
// Created by rober on 18-1-11.
//
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool IsPrim(int n);

//int main()
//{
//    int n;
//    cin>>n;
//
//    int k=0;
//    int t1=2, t2;
//    for(int i=3; i<=n; i++)
//    {
//        if(IsPrim(i))
//        {
//            t1=t2;
//            t2=i;
//            if(t2-t1==2)
//            {
//                k++;
//            }
//        }
//
//    }
//    cout<<k<<endl;
//    return 0;
//}

bool IsPrim(int n)
{
    int m=sqrt(n);
    for (int i=2; i<=m; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;

}