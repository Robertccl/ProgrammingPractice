//
// Created by rober on 18-1-18.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>


using namespace std;

/*
 * 这个代码有很多不错的用法；
 * 1.使用stringstram,可以方便获取字符串，详见61-80行
 * 2.使用sprintf 具体有什么用法见百度，这里用到的将数字格式化成字符串如1->“01”,
 * 当然用到了c语言的“%02d”,这种格式控制，将数字变成两位且不够补0
 * 3.还有一个案例不能通过
 *
 *
 *
 */

int main()
{
    char a[100]={'\0'}, b[100]={'\0'}, c[100]={'\0'}, d[100]={'\0'};
    scanf("%s%s%s%s", &a, &b, &c, &d);
    int i=0,j=0;
    bool flag=true;
    string result="";

    stringstream ss;

    while(i<strlen(a) && j<strlen(b))
    {
        if(a[i]==b[j])
        {
            if(flag)
            {
                if(a[i]>='A'&& a[i]<='G')  //得到周几
                {
                    switch(a[i])
                    {
                        case 'A':
                            result+="MON "; break;
                        case 'B':
                            result+="TUE "; break;
                        case 'C':
                            result+="WED "; break;
                        case 'D':
                            result+="THU "; break;
                        case 'E':
                            result+="FRI "; break;
                        case 'F':
                            result+="SAT "; break;
                        case 'G':
                            result+="SUN "; break;
                        default:
                            break;
                    }
                    flag=false;
                }

            }
            else                            //得到小时
            {
                if(a[i]>='A'&& a[i]<='N')
                {
                    int t=a[i]-'A' + 10;
                    ss<<t;
                    result+=ss.str();
                }
                else if(a[i]>='0' && a[i]<='9')
                {
                    int t=a[i]-'0';
                    char s[5]={'\0'};
                    sprintf(s, "%02d", t);
                    result+=s;
                }
            }
        }
        i++;
        j++;
    }
    result+=":";
    i=0;
    j=0;
    while(i<strlen(c) && j<strlen(d))
    {
        if(c[i]==d[j] && (c[i]>='A' && c[i]<='Z' || c[i]>='a' && c[i]<='z') )  //得到分钟
        {
            char s[5]={'\0'};
            sprintf(s, "%02d", i);
            result+=s;
            break;
        }
        i++;
        j++;
    }

    cout<<result<<endl;

    return 0;
}
