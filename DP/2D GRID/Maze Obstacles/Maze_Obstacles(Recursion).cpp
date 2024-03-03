#include<bits/stdc++.h>
using namespace std;

int  f(int row,int col,vector< vector< int> >&maze)
{

     if(row>0 && col>0 && maze[row][col]==-1) //extra check
            return 0;

       if(row==0 && col==0) //base case

         return 1;

       if(row<0 || col<0)   //boundary check
         return 0;

           int up=f(row-1,col,maze);
           int left= f(row,col-1,maze);

       return up+left;

}
int main(){

  int n,x,row,col;
  cin>>row>>col;

  vector< vector< int> >maze(col+1);

   for(int i=0;i<row;i++)
 {
    for(int j=0;j<col;j++)

   {
        cin>>x;
     maze[i].push_back(x);
    }

 }

  cout<<f(row-1,col-1,maze)<<endl;

}




