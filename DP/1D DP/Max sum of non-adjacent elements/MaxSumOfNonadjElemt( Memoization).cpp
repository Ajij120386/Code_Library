
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&arr,vector<int>&dp)
{
         if(ind==0) return arr[ind];

          if(ind<0) return 0;


        if(dp[ind]!=-1)
                   return dp[ind];
      int pick =f(ind-2,arr,dp)+ arr[ind];

      int notpick =f(ind-1,arr,dp)+ 0;


return dp[ind]=max(pick,notpick);

}
int main(){

  int n,x;
  cin>>n;
   vector<int>arr;
  for(int i=0;i<n;i++){
        cin>>x;
     arr.push_back(x);
  }
  vector<int>dp(n+1,-1);
  cout<<f(n-1,arr,dp)<<endl;

}


