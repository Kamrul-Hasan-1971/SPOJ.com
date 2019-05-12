#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

vector<int>v;
bool prime[100005];

void findPrime(int n)
{
    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }


    for(int i=3; i*i<=n; i+=2)
    {
        if(!prime[i])
        {
            for(int j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
        }
    }
}


int PrimeFactorization(int a)
{
    int cnt,x=1,n;

    for(int i =0;v[i]*v[i]<=a;i++)
    {
        n=v[i];
        cnt=1;
        while(a%n==0){
            cnt++;
            a=a/n;
        }
        x=x*cnt;
    }
    if(a!=1){
        x=x*2;
    }
    return x;
}

int main()
{
    int n,a,b,c,i,p,cnt=0;
    n=100002;
    findPrime(n);

    scanf("%d %d %d",&a,&b,&c);

    for(i=a; i<=b; i++)
    {
        p=PrimeFactorization(i);
        if(p==c){
            cnt++;
        }
    }
    printf("%d\n",cnt);
}
