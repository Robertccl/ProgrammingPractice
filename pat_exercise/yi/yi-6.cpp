////
//// Created by rober on 18-1-11.
////
//
//#include <iostream>
//#include <cstring>
//#include <stdio.h>
//
//using namespace std;
//
//int main() {
//    int shu[5]={0};
//    int n = 0, num = 0;
//    cin >> n;
//    num = n;
//    for (int i = 1; i < 4; i++) {
//        if(n) {
//            shu[i] = n % 10;
//            n = n / 10;
//        }
//    }
//    for(int i=3; i>0; i--)
//    {
//        for(int j=1; j<shu[i]+1; j++)
//        {
//            if(i==1)
//            {
//                cout<<j;
//            }
//            if(i==2)
//            {
//                cout<<"S";
//            }
//            if(i==3)
//            {
//                cout<<"B";
//            }
//        }
//    }
//    cout<<endl;
//}