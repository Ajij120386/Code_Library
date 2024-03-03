
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&heights,vector<int>&dp)
{
         if(ind==0) return 0;

        if(dp[ind]!=-1)
                   return dp[ind];

      int jumpOne =f(ind-1,heights,dp)+ abs(heights[ind]-heights[ind-1]);

       int jumpTwo= INT_MAX;
      if(ind>1)

       jumpTwo =f(ind-2,heights,dp)+ abs(heights[ind]-heights[ind-2]);


return dp[ind]= min(jumpOne,jumpTwo);

}
int main(){

  int n,x;
  cin>>n;
   vector<int>heights;
   vector<int>dp(n+1,-1);

  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }

  cout<<f(n-1,heights,dp)<<endl;

}

