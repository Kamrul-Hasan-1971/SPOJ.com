#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           pii              pair < string, ll>
#define           pb               push_back


vector<ll>v,v1;
bool prime[10000004];

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

    for(ll i=2; i<=n; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
        }
    }
}


ll PrimeFactorization(ll a)
{
    ll cnt,x=1,n;

    for(int i =0; v[i]*v[i]<=a; i++)
    {
        n=v[i];
        cnt=1;
        while(a%n==0)
        {
            cnt++;
            a=a/n;
        }
        x=x*(((pow(v[i],cnt))-1)/(v[i]-1));
    }
    if(a!=1)
    {
        x=x*(((a*a)-1)/(a-1));
    }
    return x;
}




int main()
{
    ll a,b=10000000,i,j,c,d,test;
    findPrime(b);
    v1.push_back(2);
    for(i=2; i*i<=1000000; i++)
    {
        d=PrimeFactorization(i*i);
        if(prime[d]==0)
        {
            v1.push_back(i*i);
        }
    }

    scanf("%lld",&test);
    while(test--)
    {
        d=0;
        scanf("%lld %lld",&a, &c);
        for(j=0;j<v1.size();j++){
            if(v1[j]>=a && v1[j]<=c){
                d++;
            }
        }
        printf("%lld\n",d);
    }

    return 0;
}
