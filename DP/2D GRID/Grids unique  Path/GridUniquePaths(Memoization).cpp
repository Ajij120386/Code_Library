#include<bits/stdc++.h>
using namespace std;

int  f(int row,int col, vector< vector< int> > &dp)
{
       if(row==0 && col==0) //reaching our destination
         return 1;

       if(row<0 || col<0)   //boundary check
         return 0;
       if(dp[row][col]!=-1)
                   return dp[row][col];

           int up=f(row-1,col,dp);

           int left= f(row,col-1,dp);

       return dp[row][col]= up+left;

}
int main(){

  int n,x,row,col;
  cin>>row>>col;

  vector< vector< int> > dp(row,vector<int>(col,-1));

  cout<<f(row-1,col-1,dp)<<endl;

}




