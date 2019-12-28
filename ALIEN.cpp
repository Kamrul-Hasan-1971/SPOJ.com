#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T ;
    scanf("%d",&T);
    while(T--)
    {
        int  a,b,c,i,sum1=0 ;
        scanf("%d%d",&a,&b);
        int ara[a+3];

        for( i = 0 ; i < a ; i++)
        {
            scanf("%d",&ara[i]);
        }
        for( i = 1 ; i < a ; i++)
        {
            ara[i] += ara[i-1];
        }
        int low = 1 ;
        int high = a ;
        int ans =  0 ;
        int res = 0, sum;

        while(low<=high)
        {
            int chk = 0 ;
            int x = 0 ;
            int ini = 0 ;
            sum = 100000000;
            int mid = (low + high) / 2 ;

            for( i = mid-1  ; i < a ; i++ )
            {
                if(ara[i]-ini<=b)
                {
                    chk=1;
                    sum = min(sum,ara[i]-ini);
                }
                ini = ara[x] ;
                x++;
            }
            if(chk==1)
            {
                ans = mid ;
                res = sum;
                low = mid + 1 ;
            }
            else
                high = mid -1 ;
        }
        printf("%d %d\n",res,ans);
    }

    return 0 ;
}

//https://www.spoj.com/problems/ALIEN/
