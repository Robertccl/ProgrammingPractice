//
// Created by rober on 18-1-9.
//

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct student
{
    char name[12];  //数组空间要开大一点，否则容易出现异常错误！！！！！！！
    char snum[12];
    int score;

};

//int main()
//{
//    int l=sizeof(student);
//
//    student s[102];
//    memset(s, 102*l, '\0');
//    int n=0, k=0;
//    cin>>n;
//    int min=0, max=0;
//    while(n--)
//    {
//        scanf("%s%s%d", &s[k].name, &s[k].snum, &s[k].score);
//        if(s[k].score>=0 && s[k].score<=100)
//        {
//            if (s[k].score > s[max].score)
//                max = k;
//            if (s[k].score < s[min].score)
//                min = k;
//            k++;
//        }
//    }
//
//    printf("%s %s\n", s[max].name, s[max].snum);
//    printf("%s %s\n", s[min].name, s[min].snum);
//
//    return 0;
//}