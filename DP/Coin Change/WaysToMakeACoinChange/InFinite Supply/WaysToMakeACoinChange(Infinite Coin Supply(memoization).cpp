

#include<bits/stdc++.h>
using namespace std;


        // ********* FOR  IND N To 0   ************

int  f(int ind,vector<int>&val,int T,vector< vector<int> >&dp)
{
         if(ind==0)
         {
             return (T%val[0]==0);

         }
  if(dp[ind][T]!=-1)
              return dp[ind][T];

         int nottake =  f(ind-1,val,T,dp) ;

         int  take=0;

      if(val[ind]<=T)
                take =  f(ind,val,T-val[ind],dp) ;


return dp[ind][T]=take+nottake;

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

          ********* FOR  IND 0 To N   ************

   int dp[301][5001];
    int f(int ind,vector<int>&val, int T, int n){
        if(T==0){
            return 1;
        }
        if(ind==n){
            return 0;
        }
        if(dp[ind][T] != -1){
            return dp[ind][T];
        }



         int nottake =  f(ind-1,val,T,n) ;

         int  take=0;

      if(val[ind]<=T)
                take =  f(ind,val,T-val[ind],n) ;


return dp[ind][T]=take+nottake;

    }

    int change(int amount, vector<int>& val) {
        memset(dp, -1, sizeof(dp));
        return f(val, 0, amount, val.size());
    }
*/


