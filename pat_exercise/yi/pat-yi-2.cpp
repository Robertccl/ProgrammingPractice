//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//
//int main()
//{
//    string arr[10]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
//    string res[10]={""};
//    char n[100]={'\0'};
//    gets(n);
//    int i=0, sum=0;
//    while(n[i] != '\0')
//    {
//        sum += n[i] - '0';
//        i++;
//    }
//    //cout<<sum<<endl;
//    int j=0;
//    while(sum!=0)
//    {
//        int k=sum%10;
//        sum=sum/10;
//        res[j++]=arr[k];
//    }
//    while(--j)
//    {
//        cout<<res[j]<<" ";
//    }
//    cout<<res[j];
//    return 0;
//}