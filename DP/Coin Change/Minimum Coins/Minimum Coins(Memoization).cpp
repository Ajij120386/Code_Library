#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&val,int T,vector< vector<int> >&dp)
{
         if(ind==0)
         {
                if(T%val[0]==0)
                    return T/val[0];
               else
                  return 1e9;
         }

        if(dp[ind][T]!=-1)
              return dp[ind][T];

         int nottake =  0 +f(ind-1,val,T,dp) ;

      int  take=INT_MAX;

      if(val[ind]<=T)
                take =  1+f(ind,val,T-val[ind],dp) ;


return dp[ind][T] = min(take,nottake);

}
int main(){

  int n,W,T,x;
  cin>>n>>T;
   vector<int>val;

 for(int i=0;i<n;i++)
    {
          cin>>x;
          val.push_back(x);

    }
 vector< vector<int> >dp( n,vector<int>(T+1,-1));

  cout<<f(n-1,val,T,dp)<<endl;

}
/*
3 7
1 2 3
*/



