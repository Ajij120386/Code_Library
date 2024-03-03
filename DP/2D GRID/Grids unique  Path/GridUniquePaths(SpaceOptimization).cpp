
#include<bits/stdc++.h>
using namespace std;

int  f(int row,int col)
{

    vector< int>prev(col,0);


    for(int i=0;i<row;i++)

  {
         vector< int>cur(col,0);

         for(int j=0;j<col;j++)
     {

         if(i==0 && j==0)  //base case
                   cur[j]=1;

         else{
              int up=0;
              int left=0;

              if(i>0)  //boundary check
                   up=prev[j];
              if(j>0)
                   left=cur[j-1];

                   cur[j]=left+up;
            }

      }
        prev=cur;

    }



       return prev[col-1];

}
int main(){

  int n,x,row,col;
  cin>>row>>col;


  cout<<f(row,col)<<endl;

}





