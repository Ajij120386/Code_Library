
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&price,int N,vector< vector<int> >&dp)
{
         if(ind==0)
         {
             return N*price[0];
         }
             if(dp[ind][N]!=-1)
                  return dp[ind][N];

         int nottake =  0 +f(ind-1,price,N,dp) ;

      int  take=INT_MIN;
      int rodlength=ind+1;
      if(rodlength<=N)
                take =  price[ind]+f(ind,price,N-rodlength,dp) ;


return dp[ind][N]= max(take,nottake);

}
int main(){

  int n,W,x;
  cin>>n;
   vector<int>price;
  for(int i=0;i<n;i++)
    {
        cin>>x;
        price.push_back(x);

    }

 vector< vector<int> >dp( n,vector<int>(W+1,-1));

  cout<<f(n-1,price,n,dp)<<endl;

}
/*
5
2 5 7 8 10
*/



