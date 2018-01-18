////
//// Created by rober on 18-1-11.
////
//
//#include <iostream>
//#include <cstring>
//#include <stdio.h>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//
//    int shu[110]={0};
//    int data[110]={0};
//    int n=0, num=0;
//    stack<int> s;
//
//    cin>>n;
//    for(int i=0; i<n; i++)
//    {
//        cin>>data[i];
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        num=data[i];
//        if(shu[num]>0)
//            continue;
//        while(num != 1) {
//            if(num<=100)
//                shu[num]++;
//            if (num % 2 == 0) {
//                num = num / 2;
//                if(num<=100)
//                    shu[num]++;
//            } else {
//                num=(num * 3 + 1) / 2;
//                if(num<=100)
//                    shu[num]++;
//            }
//        }
//    }
//    for(int i=1; i<101; i++)
//    {
//        if(shu[i]==1)
//        {
//            s.push(i);
//        }
//    }
//
//    while(!s.empty())
//    {
//        cout<<s.top();
//        s.pop();
//        if(!s.empty())
//            cout<<" ";
//    }
//
//
//    return 0;
//}