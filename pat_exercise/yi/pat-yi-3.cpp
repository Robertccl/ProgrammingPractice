//
// Created by rober on 18-1-8.
//
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;


bool Judger(char *c);

//int main() {
//    int n=0;
//    scanf("%d", &n);
//    char arr[100] = {'\0'};
//
//    while(n--)
//    {
//        scanf("%s", &arr);
//        //puts(arr);
//        if(Judger(arr))
//            cout<<"YES"<<endl;
//        else
//            cout<<"NO"<<endl;
//        memset(arr, 100, '\0');
//    }
//}

bool Judger(char *c)
{
    int count1=0, count2=0, count3=0;
    int countP=0, countT=0;
    bool result=true;
    for(int j=0;j<strlen(c);j++){
        if(c[j] != 'P' && c[j] != 'A' && c[j] != 'T'){
            result = false;
            break;
        }
        if(c[j] == 'P'){
            countP ++;
            if(countP == 2){
                result = false;
                break;
            }
        }
        if(c[j] == 'T'){
            countT ++;
            if(countT == 2){
                result = false;
                break;
            }
        }
    }
    if(result){
        string s = c;
        count1 = s.find("P");
        count2 = s.find("A");
        count3 = s.find("T");
        if(count1 == -1 || count2 == -1 || count3 == -1){
            result = false;
        }
        else{
            result = ((count1 * (count3 - count1 - 1)) == (strlen(c) - count3 - 1)) ? true : false;
        }
    }
    return result;
}

