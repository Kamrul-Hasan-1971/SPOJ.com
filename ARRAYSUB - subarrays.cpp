#include<bits/stdc++.h>
using namespace std;

int ara[1000006];

void printKMax(int a , int b )
{
    deque<int>dq;
    int i ;
    for( i = 0 ; i < b ; i++ )
    {
        while((!dq.empty()) && ara[i] >= ara[dq.back()] )
            dq.pop_back();
        dq.push_back(i);
    }

    for( ; i<a ; i++ )
    {
        printf("%d ",ara[dq.front()]);

        while((!dq.empty()) && dq.front() <= i-b )
            dq.pop_front();

        while((!dq.empty()) && ara[i] >= ara[dq.back()] )
            dq.pop_back();
        dq.push_back(i);
    }
    printf("%d\n",ara[dq.front()]);
}

int main()
{
    int  a,b,c,i,sum1=0;
    scanf("%d",&a);

    for( i = 0 ;i < a ; i++)
    {
        scanf("%d",&ara[i]);
    }
    scanf("%d",&b);

    printKMax( a , b ) ;

    return 0 ;
}

//https://www.spoj.com/problems/ARRAYSUB/
