
#include<bits/stdc++.h>
using namespace std;

int  f(int row,int col,vector< vector< int> >&mat,vector< vector< int> > &dp)
{
       if(row==0 && col==0) //base case
         return mat[0][0];

       if(row<0 || col<0)   //boundary check
             return 1e9;

         if(dp[row][col]!=-1)
                   return dp[row][col];

           int up=mat[row][col]+f(row-1,col,mat,dp);
           int left= mat[row][col]+f(row,col-1,mat,dp);

       return dp[row][col]= min(up,left);

}
int main(){

  int n,x,row,col;
  cin>>row>>col;

  vector< vector< int> >mat(col+1);

   for(int i=0;i<row;i++)
 {
    for(int j=0;j<col;j++)

   {
        cin>>x;
     mat[i].push_back(x);
    }

 }

  vector< vector< int> > dp(row,vector<int>(col,-1));

  cout<<f(row-1,col-1,mat,dp)<<endl;

}




