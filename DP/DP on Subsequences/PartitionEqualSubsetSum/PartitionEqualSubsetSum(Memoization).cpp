#include<bits/stdc++.h>
using namespace std;

bool f(int ind, vector< int> &arr,int T,vector<vector<int>>&dp)
{
        if(T==0)
               return true;
         if(ind==0)
                 return (arr[ind]==T);
if(dp[ind][T]!=-1)
        return dp[ind][T];
          bool nottake =  f(ind-1,arr,T,dp);
          bool take =false;
      if(arr[ind]<=T)
               take =  f(ind-1,arr,T-arr[ind],dp);

  return dp[ind][T]=  take || nottake;


}
int main(){

  int n,m,x,row,col,TotalSum=0;
  cin>>n;

  vector< int>arr;
   for(int i=0;i<n;i++)
 {

        cin>>x;
       arr.push_back(x);
        TotalSum+=x;

    }


    if(TotalSum%2){
       cout<<0<<endl;
 return 0;
   }
   int target=TotalSum/2;
   vector<vector<int>> dp(n,vector<int>(target+1,-1));
   cout<<f(n-1,arr,target,dp)<<endl;
}







