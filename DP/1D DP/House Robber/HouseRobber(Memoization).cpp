
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&arr,vector<int>&dp)
{
         if(ind==0) return arr[ind];

          if(ind<0) return 0;
          if(dp[ind]!=-1) return dp[ind];
      int pick =f(ind-2,arr,dp)+ arr[ind];

      int notpick =f(ind-1,arr,dp)+ 0;


return dp[ind]= max(pick,notpick);

}
int main(){

  int n,x;
  cin>>n;
   vector<int>arr1,arr2;

  for(int i=0;i<n;i++){
        cin>>x;
        if(i!=n-1)
         arr1.push_back(x);
         if(i!=0)
         arr2.push_back(x);
  }

     vector<int>dp(n+1,-1);
 int Firsthalf=f(n-2,arr1,dp);

       vector<int>dp1(n+1,-1);
 int Secondhalf=f(n-2,arr2,dp1);

  cout<<max(Firsthalf,Secondhalf)<<endl;

}



