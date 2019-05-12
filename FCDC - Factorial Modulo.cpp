#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#define       gcd(a, b)            __gcd(a,b)
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
}
int firstFactorialDivisibleNumber(int a)
{
    int i,x=a;
    for(i=1;i<=a;i++){
        if(prime[x]==0){
            return x;
        }
        x=x/gcd(i,x);
        if(x==1){
            break;
        }
    }
    return i;
}

int countFactorial_A_not_B(int a,int b)
{
    return (firstFactorialDivisibleNumber(b)-firstFactorialDivisibleNumber(a));
}

int main()
{
    int a,b,i,res,n;
    n=10000001;
    findPrime(n);
    scanf("%d %d", &a, &b);
    res=countFactorial_A_not_B(a,b);
    if(res<0){
        res=0;
    }
    printf("%d\n", res);
}
