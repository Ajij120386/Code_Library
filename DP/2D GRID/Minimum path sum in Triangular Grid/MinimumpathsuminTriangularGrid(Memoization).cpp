#include<bits/stdc++.h>
using namespace std;

int  f(int i,int j,vector< vector< int> >&mat,int n,vector< vector< int> > &dp)

{

       if(i==n-1) //base case
             return mat[i][j];
//there is no out  of boundary case

if(dp[i][j]!=-1)
                   return dp[i][j];

  int down = mat[i][j]+f(i+1,j,mat,n,dp);
  int diagonal = mat[i][j]+f(i+1,j+1,mat,n,dp);

  return dp[i][j]= min(down, diagonal);


}
int main(){

  int n,x,row,col;
  cin>>n;

  vector< vector< int> >mat(n+1);
   for(int i=0;i<n;i++)
 {
    for(int j=0;j<=i;j++)

   {
        cin>>x;
     mat[i].push_back(x);
    }

 }
vector< vector< int> > dp(n,vector<int>(n,-1));
  cout<<f(0,0,mat,n,dp)<<endl;

}





