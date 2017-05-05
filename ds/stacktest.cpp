//#include <iostream>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
//int main()
//{
//    stack<int > test;
//    queue<int > order[1000];
//    int q[1000]={0}, head=0, tail=0;
//    int a=0;
//    bool yesOrNo[1000]={false};
//
//    int maxSize=0, num=0, N=0;
//    cin>>maxSize>>num>>N;
//
//    for(int i=0; i<N; i++)
//    {
//        for(int j=0; j<num; j++)
//        {
//            scanf("%d", &a);
//            order[i].push(a);
//        }
//    }
//    int k=0;
//    int flag=0;
//    while(k < N)
//    {
//        flag=0;
//        head=1;
//        tail=num+1;
//        while(!test.empty())
//        {
//            test.pop();
//        }
//
//        while (head<=tail)
//        {
//            if(!test.empty())
//            {
//                if(test.top() == order[k].front())
//                {
//                    test.pop();
//                    order[k].pop();
//                    flag++;
//                    continue;
//                }
//            }
//
//            int a = head;
//            if (test.size() < maxSize)
//            {
//                if(a == order[k].front())
//                {
//                    flag++;
//                    head++;
//                    order[k].pop();
//                }
//                else
//                {
//                    test.push(a);
//                    head++;
//                }
//            }
//            else
//            {
//                flag = -1;
//                break;
//            }
//        }
//        if (flag == -1)
//        {
//            yesOrNo[k] = false;
//        }
//        else if(flag==num)
//        {
//            yesOrNo[k] = true;
//        }
//
//        k++;
//    }
//
//    for(int i=0; i<N; i++)
//    {
//        if(yesOrNo[i])
//            cout<<"YES"<<endl;
//        else
//            cout<<"NO"<<endl;
//    }
//
//    return 0;
//}