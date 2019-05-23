#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define pii              pair <long long,long long>



vector<ll>v,v1,v2,v3,v4,v5;
int main()
{
    ll j,i,a,b,c,d,e,sum=0,x;

    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>b>>c>>d>>e;
        v.pb(b);
        v1.pb(c);
        v2.pb(d);
        v3.pb(e);
    }
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            v4.pb(v[i]+v1[j]);
        }
    }
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            v5.pb(v2[i]+v3[j]);
        }
    }
    sort(v4.begin(),v4.end());
    sort(v5.begin(),v5.end());

    for(i=0; i<v4.size(); i++)
    {
        x=upper_bound(v5.begin(),v5.end(),-v4[i])-lower_bound(v5.begin(),v5.end(),-v4[i]);
        sum=sum+x;
    }
    cout<<sum;
    return 0;
}
