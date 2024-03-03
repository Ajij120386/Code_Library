
#include<bits/stdc++.h>
using namespace std;

int  f(vector<int>&arr)
{
    int n=arr.size();
        vector<int>dp(n+1,0);

      dp[0]=arr[0];


       for(int i=1;i<n;i++)
{


        int pick =arr[i];
        if(i>1)
               pick+=dp[i-2];

       int notpick =dp[i-1]+ 0;

       dp[i]= max(pick,notpick);

 }
   return dp[n-1] ;

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


 int Firsthalf=f(arr1);

 int Secondhalf=f(arr2);

  cout<<max(Firsthalf,Secondhalf)<<endl;

}




