////
//// Created by rober on 18-1-17.
////
//
//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <cstring>
//
//using namespace std;
//题

/*
 * 题目很简单，有一个小问题需要注意，计算a[2]的时候因为a[2]的结果可能为0,
 * 所以判断a[2]是否为0输出N的方法是错误的，要判断有没有符合a[2] 的情况的
 * 个数才能正确解答本
 */


//int main()
//{
//    int n;
//    int x;
//
//    int a[6]={0};
//    int flag=1, f3=0;
//    int k=0;
//
//    cin>>n;
//
//    for (int i=0; i<n; i++)
//    {
//        cin >> x;
//        if (x % 5 == 0 && x % 2 == 0)
//            a[1] += x;
//
//        if (x % 5 == 1)
//        {
//            a[2] += flag * x;
//            flag *= -1;
//            f3++;
//        }
//
//        if (x % 5 == 2)
//            a[3]++;
//
//        if (x % 5 == 3)
//        {
//            a[4] += x;
//            k++;
//        }
//
//        if(x%5 == 4)
//        {
//            if(x>a[5])
//                a[5]=x;
//        }
//    }
//    for(int i=1; i<4; i++)
//    {
//        if(i!=2)
//        {
//            if(a[i]!=0)
//                cout<<a[i]<<" ";
//            else
//                cout<<"N ";
//        }
//        else
//        {
//            if(f3==0)
//                cout<<"N ";
//            else
//                cout<<a[i]<<" ";
//        }
//    }
//
//    if(k==0)
//        cout<<"N ";
//    else
//    {
//        float aver = (float) a[4] / k;
//        printf("%.1f ", aver);
//    }
//
//    if(a[5]!=0)
//        cout<<a[5]<<endl;
//    else
//        cout<<"N"<<endl;
//
//    return 0;
//}