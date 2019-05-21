#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int


ll sequence(string y,string x)
{
    ll p=0;
    for(ll i=0; i<y.size(); i++)
    {
        if(y[i]==x[p])
        {
            p++;
        }
    }
    if(p==x.size())
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


string match(string x,ll m)
{
    string s="";
    for(ll i=0; i<x.size(); i++)
    {
        for(ll j=0; j<m; j++)
        {
            s+=x[i];
        }
    }
    return s;
}



int main()
{
    string x,y;
    ll n,h,l,m;
    cin>>n;
    while(n--)
    {
        x=y="";
        cin>>x>>y;
        h=y.size()/x.size();
        l=0;

        while(l<=h)
        {
            m=(l+h)/2;

            if(sequence(y,match(x,m)))
            {
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        cout<<h<<endl;

    }
    return 0;
}
