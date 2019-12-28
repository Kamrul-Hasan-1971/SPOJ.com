#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int

ll ara[300005];

int main()
{
    ll  a,b,c,i,sum1=0;
    scanf("%lld%lld",&a,&b);

    for( i = 0 ;i < a ; i++)
    {
        scanf("%lld",&ara[i]);
    }
    ll x = 0 , mx = 0 ;
    for( i =0 ; i < a ; i++ )
    {
        sum1 += ara[i] ;
        if(sum1>b)
        {
            mx = max( mx , sum1 - ara[i] ) ;
            while(x<=i && sum1 > b )
            {
                sum1-=ara[x];
                x++;
            }
        }
    }
    mx = max(sum1,mx);
    printf("%lld\n",mx);

    return 0 ;
}
//https://www.spoj.com/problems/HOTELS/
