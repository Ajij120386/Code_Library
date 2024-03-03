
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&heights,int k,vector<int>&dp)
{
         if(ind==0) return 0;


      int mmsteps= INT_MAX;

        if(dp[ind]!=-1)
              return dp[ind];
        for(int i=1;i<=k;i++)

      {

           if(ind-i>=0)
          {

            int jump =f(ind-i,heights,k,dp)+ abs(heights[ind]-heights[ind-i]);

            mmsteps=min(jump,mmsteps);
           }

      }
      return dp[ind]=mmsteps;
}
int main(){

  int n,x,k;
  cin>>n>>k;
   vector<int>heights;
    vector<int>dp(n+1,-1);
  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }

  cout<<f(n-1,heights,k,dp)<<endl;

}

