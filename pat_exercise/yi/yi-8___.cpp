//
// Created by rober on 18-1-11.
//
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

void Swap(int a[], int from, int end)
{
    while(from<end){
        //a[from]^= a[end]^= a[from]^= a[end];   //a^=b ======  a=a^b  异或赋值运算符    #注释1
        a[from]=a[from]^a[end];
        a[end]^=a[from];
        a[from]^=a[end];                         //交换两个数的值，不用临时变量的方法，    #注释2

                                                //注释1 与 注释2 格式不同功能一样
        from++;
        end--;
    }
}

//int main(void)
//{
//    int M,N;
//    scanf("%d",&N);
//    scanf("%d",&M);
//    int a[N];
//    int m= M%N;
//    for(int i= 0; i< N; i++)
//        scanf("%d",a+i);
//    Swap(a,0,N-1);//先整体翻转过来使数列倒序
//
//    Swap(a,0,m-1);//然后部分翻转实现循环右移
//    Swap(a,m,N-1);
//    for(int i= 0; i< N-1; i++)
//        printf("%d ",a[i]);
//    printf("%d",a[N-1]);
//
//}
//此法甚妙，需用心牢记,网上找的



//超时了，，，，，所以不能用常规方法，需要用到一个技巧，，，，，见下
//int main()
//{
//    int n=0,m=0;
//    int data[110]={0};
//
//    cin>>n>>m;
//    for (int i=0; i<n; i++)
//    {
//        cin>>data[i];
//    }
//    for(int i=0; i<m; i++)
//    {
//        int j=i;
//        int num=data[j];
//        int swap=0;
//
//        data[j]=-1;
//        j=(j+m)%n;
//        while(data[j] != -1) {
//            swap=data[j];
//            data[j]=num;
//            num=swap;
//            j=(j+m)%n;
//        }
//        data[j]=num;
//    }
//
//    for(int i=0; i<n-1; i++)
//    {
//        cout<<data[i]<<" ";
//    }
//    cout<<data[n-1];
//
//    return 0;
//}




