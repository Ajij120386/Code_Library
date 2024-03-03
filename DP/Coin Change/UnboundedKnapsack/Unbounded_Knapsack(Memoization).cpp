


#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&val,vector<int>&wt,int W, vector< vector<int> >&dp)
{
         if(ind==0)
         {
               return (W/wt[0])*val[0];
         }
  if(dp[ind][W]!=-1)
              return dp[ind][W];

    int nottake =  0 +f(ind-1,val,wt,W,dp) ;

      int  take=INT_MIN;
      if(wt[ind]<=W)
                take =  val[ind]+f(ind,val,wt,W-wt[ind],dp) ;


return dp[ind][W]=  max(take,nottake);

}
int main(){

  int n,W,x;
  cin>>n>>W;
   vector<int>wt,val;
  for(int i=0;i<n;i++)
    {
        cin>>x;
        wt.push_back(x);

    }
 for(int i=0;i<n;i++)
    {
          cin>>x;
          val.push_back(x);

    }
   vector< vector<int> >dp( n,vector<int>(W+1,-1));

  cout<<f(n-1,val,wt,W,dp)<<endl;

}
/*
3 10
2 4 6
5 11 13
*/

