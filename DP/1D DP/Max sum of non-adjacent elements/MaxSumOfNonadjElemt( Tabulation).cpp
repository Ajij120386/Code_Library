
#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,x;
  cin>>n;

    vector<int>arr;

  for(int i=0;i<n;i++){
        cin>>x;
     arr.push_back(x);
  }
   vector<int>dp(n+1,0);
      dp[0]=arr[0];


 for(int i=1;i<n;i++){


        int pick =arr[i];
        if(i>1)
               pick+=dp[i-2];

       int notpick =dp[i-1]+ 0;

       dp[i]= max(pick,notpick);
 }
   cout<<dp[n-1]<<endl;
}


