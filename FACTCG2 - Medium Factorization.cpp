#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#define           ll               long long int

vector<int>v;
bool prime[10000003];

void findPrime(int n)
{
    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }

    prime[1]=true;

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

    for(int i=1; i<=n; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
        }
    }
}
int main()
{
    int n,a,b,i;
    n=10000001;
    findPrime(n);
    while(scanf("%lld",&a)!=EOF)
    {
        if(a==1)
        {
            printf("1\n");
            continue;
        }
        if(prime[a]==0)
        {
            printf("1 x %d\n",a);
            continue;
        }
        printf("1");
        for(i=0;; i++)
        {
            if(a%v[i]==0)
            {
                while(1)
                {
                    if(a%v[i]!=0)
                    {
                        break;
                    }
                    printf(" x %d",v[i]);
                    a=a/v[i];
                }
            }
            if(a==1){
                printf("\n");
                break;
            }
            if(prime[a]==0)
            {
                printf(" x %d\n",a);
                break;
            }
        }
    }

}
