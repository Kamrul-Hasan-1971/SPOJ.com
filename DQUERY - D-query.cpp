#include<bits/stdc++.h>
using namespace std;
#define  ll   int
const ll maxn = 1000006;
ll K, ans[maxn], a[maxn], sum,cnt[maxn];
struct Query
{
    int index, L, R;
    bool operator<(const Query& other)
    {
        return L/K < other.L/K ||
               (L/K == other.L/K && R<other.R);
    }

}query[maxn];

void add(ll indx)
{
    ll x = ++cnt[a[indx]];
    if(x==1)
        sum++;
}
void del(ll indx)
{
    ll x = --cnt[a[indx]];
    if(x==0)
        sum--;
}

int main()
{
    ll T=1,j;
    for( j = 1 ; j<= T ; j++)
    {
        ll i, n, q, L=1, R=0;
        scanf("%d",&n);
        K = sqrt(n);
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&q);
        for(i=1; i<=q; i++)
        {
            scanf("%d%d",&query[i].L,&query[i].R);
            query[i].index = i;
        }
        sort(query+1, query+q+1);
        sum=0;
        for(i=1; i<=q; i++)
        {
            while(R<query[i].R)
                add(++R);
            while(L<query[i].L)
                del(L++);
            while(R>query[i].R)
                del(R--);
            while(L>query[i].L)
                add(--L);
            ans[query[i].index] = sum;
        }
        for(int i=1; i<=q; i++)
            printf("%d\n",ans[i]);
        memset(cnt,0,sizeof cnt);
    }
    return 0;
}
//https://www.spoj.com/problems/DQUERY/
