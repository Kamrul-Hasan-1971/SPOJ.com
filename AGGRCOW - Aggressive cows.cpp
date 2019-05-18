#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back

vector<ll>v;
ll ans;

void binarySearch(ll l, ll r,ll N,ll E)
{
    while (l <= r)
    {
        ll cnt=E-1;
        ll f;
        ll m = (l +r) / 2;
        ll x=0;
        while(cnt--)
        {
            f=v[x]+m;
            x=lower_bound(v.begin(),v.end(),f)-v.begin();
            if(x>=N)
            {
                cnt++;
                break;
            }
            if(cnt==0){
                break;
            }
        }



        if (cnt == 0)
        {
            ans=m;
            l=m+1;
        }
        else
            r = m - 1;
    }
}

int main()
{
    ll test,N,E,i,a,start,endd,mx;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld\n",&N, &E);
        for(i=0; i<N; i++)
        {
            scanf("%lld", &a);
            v.pb(a);
        }
        sort(v.begin(),v.end());
        mx=v[N-1];
        binarySearch(0,mx,N,E);
        printf("%lld\n",ans);
        v.clear();
    }
    return 0;
}
