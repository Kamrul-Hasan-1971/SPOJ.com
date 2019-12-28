#include<bits/stdc++.h>
using namespace std;

#define           CIN                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll                 long long int
#define           pii                pair < ll, ll>
#define           fs                 first
#define           scnd               second
#define           pb                 push_back
#define           all(v)             v.begin(),v.end()

vector<pii>v1;
map<ll,ll>mp;
multiset<ll>mst;
multiset<ll>::iterator it;
multiset<ll>::reverse_iterator it2;

int main()
{
    ll  a,b,c,i,j;
    scanf("%lld%lld",&a,&b);

    for( i = 1 ; i <= a ; i++ )
    {
        for( j = 1 ; j <= b ; j++ )
        {
            scanf("%lld",&c);
            v1.pb({c,i});
        }
    }
    sort(all(v1));

    ll sz = a * b ;
    ll res = 1000000005 ;
    ll x = 0 ;

    for( i = 0 ; i < sz ; i++ )
    {
        if(mp.size()==a)
        {
            while(mp.size()==a){
            it = mst.begin();
            it2= mst.rbegin() ;
            res = min( res , *it2-*it ) ;
            if(mp[v1[x].scnd]==1)
                mp.erase(v1[x].scnd);
            else
                mp[v1[x].scnd]--;
            it = mst.lower_bound(v1[x].first);
            mst.erase(it);
            x++;
            }
        }
        mp[v1[i].scnd]++;
        mst.insert(v1[i].fs );
    }
    printf("%lld\n",res);
    return 0 ;
}
//https://www.spoj.com/problems/KOIREP/
