

#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll n, k;
ll val[55], c[55];
ll dp[52][22][1002];

int  f(int ind,int cnt,int T)
{
         if(ind==n)
         {
            if(T==0)
               return 1;
          else
             return 0;

         }

  if(dp[ind][cnt][T]!=-1)
              return dp[ind][cnt][T];


         int nottake =  f(ind+1,0,T) ;

         int  take=0;

      if(val[ind]<=T && cnt<c[ind])
                take =  f(ind,cnt+1,T-val[ind]) ;


return dp[ind][cnt][T]=(take+nottake)%mod;

}

int main()
{
    ll T;
    cin>>T;
    for(ll tc=1; tc<=T; tc++)
    {
        cin>>n>>k;
        memset(dp, -1, sizeof(dp));
        for(ll i=0; i<n; i++)
        {
            cin>>val[i];
        }
        for(ll i=0; i<n; i++)
        {
            cin>>c[i];
        }

        printf("Case %lld: %lld\n", tc, (f(0, 0, k) ));
    }
    return 0;
}
/*
2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1

*/


