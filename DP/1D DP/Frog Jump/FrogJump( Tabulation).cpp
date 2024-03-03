
#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,x;
  cin>>n;

    vector<int>heights;

  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }
   vector<int>dp(n+1,0);
      dp[0]=0;


 for(int i=1;i<n;i++){

        int jumpOne =dp[i-1]+ abs(heights[i]-heights[i-1]);

       int jumpTwo= INT_MAX;
      if(i>1)

       jumpTwo =dp[i-2]+ abs(heights[i]-heights[i-2]);

       dp[i]= min(jumpOne,jumpTwo);
 }
   cout<<dp[n-1]<<endl;
}

