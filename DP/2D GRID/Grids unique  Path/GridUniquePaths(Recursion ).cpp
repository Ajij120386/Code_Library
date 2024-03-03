#include<bits/stdc++.h>
using namespace std;

int  f(int row,int col)
{
       if(row==0 && col==0) //base case
         return 1;

       if(row<0 || col<0)   //boundary check
         return 0;

           int up=f(row-1,col);
           int left= f(row,col-1);

       return up+left;

}
int main(){

  int n,x,row,col;
  cin>>row>>col;


  cout<<f(row-1,col-1)<<endl;

}



