
#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,x,k;
  cin>>n>>k;

    vector<int>heights;

  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }
   vector<int>dp(n+1,0);
      dp[0]=0;


 for(int i=1;i<n;i++)
{
  int mmsteps= INT_MAX;

      for(int j=1;j<=k;j++)
    {
        if(i-j>=0)
        {

            int jump =dp[i-j]+ abs(heights[i]-heights[i-j]);
             mmsteps= min(jump,mmsteps);

         }
     }
     dp[i]=mmsteps;
}
   cout<<dp[n-1]<<endl;
}


