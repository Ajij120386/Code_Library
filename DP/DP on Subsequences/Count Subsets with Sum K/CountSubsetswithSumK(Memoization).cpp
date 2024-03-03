
#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector< int> &arr,int T,vector<vector<int>>&dp)
{
    /*
          //when our array constraint 1<=arr[i],then this base case will use

        if(T==0)
               return 1;

         if(ind==0)
                  return (arr[ind]==T)

    */

     //when our array constraint 0<=arr[i], then this base case will use

        if(ind==0){

                if(T==0 && arr[0]==0)
                         return 2;
                if(T==0 || T==arr[0])
                       return 1;

                       return 0;
        }
        if(dp[ind][T]!=-1)
                  return dp[ind][T];

          int nottake =  f(ind-1,arr,T,dp);
          int take =0;
      if(arr[ind]<=T)
               take =  f(ind-1,arr,T-arr[ind],dp);

 return dp[ind][T]= take+nottake;


}
int main(){

  int n,m,x,row,col,T;
  cin>>n>>T;

  vector< int>arr;
   for(int i=0;i<n;i++)
 {

        cin>>x;
       arr.push_back(x);

    }
vector<vector<int>> dp(n,vector<int>(T+1,-1));

   cout<<f(n-1,arr,T,dp)<<endl;

}





