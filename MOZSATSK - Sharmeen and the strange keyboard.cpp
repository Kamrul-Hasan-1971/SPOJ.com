#include<bits/stdc++.h>
using namespace std;

#define          ll                     long long int

string s1 ;
vector<ll>v1,vec[100005];
ll l,visited[100005], level[100005], x, y, z;

void create(ll pos)
{
    if(v1[pos]==0)
    {
        x = 9 ;
        y = 1 ;
        z = 0 ;
    }
    else if (v1[pos] == 9)
    {
        x = 9 ;
        y = 8 ;
        z = 0 ;
    }
    else
    {
        x = v1[pos]+1;
        y = v1[pos]-1;
        z = v1[pos] ;
    }

    if( pos+2 < l )
    {
        if(v1[pos+2]==x || v1[pos+2] == y || v1[pos+2] == z )
        {
            vec[pos].emplace_back(pos+2);
            vec[pos+2].emplace_back(pos);
        }
    }
    if( pos-2 >= 0 )
    {
        if(v1[pos-2]==x || v1[pos-2] == y || v1[pos-2] == z )
        {
            vec[pos].emplace_back(pos-2);
            vec[pos-2].emplace_back(pos);
        }
    }

    if( pos+1 < l )
    {
        if(v1[pos+1]==x || v1[pos+1] == y || v1[pos+1] == z )
        {
            vec[pos].emplace_back(pos+1);
            vec[pos+1].emplace_back(pos);
        }
    }

    if( pos-1 >= 0 )
    {
        if(v1[pos-1]==x || v1[pos-1] == y || v1[pos-1] == z )
        {
            vec[pos].emplace_back(pos-1);
            vec[pos-1].emplace_back(pos);
        }
    }
}

ll bfs(ll m)
{
    visited[m] = 1 ;
    level[m] = 0 ;
    queue<ll>qu;
    qu.push( m ) ;

    while( !qu.empty() )
    {
        ll x = qu.front() ;
        if( x == l-1 )
        {
            return 1 ;
        }
        qu.pop();

        for( ll i = 0 ; i < vec[x].size() ; i++ )
        {
            ll p = vec[x][i] ;

            if( !visited[p] )
            {
                visited[p] = 1 ;
                level[p] = level[x]+1;
                qu.push(p);
            }
        }
    }
    return 0 ;
}


int main()
{
    ll i;
    cin >> s1 ;

    for( i = 0 ; i < s1.size() ; i++ )
    {
        v1.emplace_back(s1[i]-'0');
    }
    l = v1.size() ;

    for( i = 0 ; i < l ; i++ )
    {
        create(i);
    }

    ll p =  bfs(0);

    if( p == 0 )
    {
        cout<<"no";
    }
    else
    {
        cout<<"yes"<<endl;
        cout<<level[l-1]<<endl;
    }

    return 0;
}

//https://www.spoj.com/problems/MOZSATSK/en/
