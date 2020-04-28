#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int
ll ara[1000006],L[1000006];
int main()
{
    ll a, i,b,T;
    cin>>T;
    while(T--)
    {
        cin >> a ;
        for( i = 0 ; i < a ; i++) cin >> ara[i];
        cin>>b;
        for( i = 0 ; i <= b ; i++) L[i]=-1;
        ll len=1;
        L[0]=ara[0];
        for( i = 1 ; i < a ; i++)
        {
            ll indx = lower_bound(L,L+len,ara[i])-L;
            if(indx==len && len<b) len++;
            indx = min(indx,b-1);
            if(L[indx]!=-1 ) L[indx]=min(ara[i],L[indx]);
            else L[indx]=ara[i];
        }
        cout<<L[b-1]<<endl;
    }
    return 0 ;
}
//https://www.spoj.com/problems/NDS/fbclid=IwAR1dtZ6vzr4yNcrEcMumFQQ1lK-wQRvosvMEes0nRGoxgrrb8lmIe7zle60
