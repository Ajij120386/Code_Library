
#include<bits/stdc++.h>
using namespace std;

int  f(int row,int col)
{

    vector< vector< int> > dp(row,vector<int>(col,0));


    for(int i=0;i<row;i++)

  {

         for(int j=0;j<col;j++)
     {

         if(i==0 && j==0)  //base case
                   dp[i][j]=1;

         else{
              int up=0;
              int left=0;

              if(i>0)  //boundary check
                   up=dp[i-1][j];
              if(j>0)
                   left=dp[i][j-1];

                   dp[i][j]=left+up;
            }

      }


    }



       return dp[row-1][col-1];

}
int main(){

  int n,x,row,col;
  cin>>row>>col;


  cout<<f(row,col)<<endl;

}




