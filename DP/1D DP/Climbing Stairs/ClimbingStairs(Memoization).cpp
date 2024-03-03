#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&dp)
{
         if(ind==0) return 1;

         if(ind==1) return 1;

           if(dp[ind]!=-1)
              return dp[ind];

       return dp[ind]=f(ind-1,dp)+f(ind-2,dp);



}
int main(){

  int n;
  cin>>n;
  vector<int>dp(n+1,-1);

  cout<<f(n,dp)<<endl;

}


