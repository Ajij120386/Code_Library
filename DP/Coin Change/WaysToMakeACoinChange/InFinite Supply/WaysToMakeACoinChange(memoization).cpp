

#include<bits/stdc++.h>
using namespace std;

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
3 4
1 2 3
*/


