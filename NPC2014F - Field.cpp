#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int

char ara[100005];
map<char,ll>mp,mp2,mp3;

int main()
{
    ll  a,b,c,i,j;
    char ch ;
    scanf("%lld",&a);
    scanf("%s",&ara);
    scanf("%lld",&b);

    for( i = 1 ; i <= b ; i++ )
    {
        scanf("%lld",&c);
        getchar();
        scanf("%ch",&ch);
        mp2[ch]=c;
    }
    ll x = 0,res = 100000000;
    for( i = 0 ; i < a ; i++ )
    {
        mp[ara[i]]++;
        if(mp2.count(ara[i]))
        {
            if(mp2[ara[i]]==mp[ara[i]])
            {
                mp3[ara[i]]=1;
            }
        }
        if(mp3.size()==b)
        {
            while(mp3.size()==b)
            {
                res = min( res, ((i - x) + 1) ) ;

                mp[ara[x]]--;

                if(mp[ara[x]]<mp2[ara[x]])
                {
                    mp3.erase(ara[x]);
                }
                x++;
            }
        }
    }
    if(res==100000000)
    {
        printf("Andy rapopo\n");
    }
    else printf("%lld\n",res);

    return 0 ;
}
//https://www.spoj.com/problems/NPC2014F/
