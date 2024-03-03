#include<bits/stdc++.h>
using namespace std;

int  f(int i,int j,vector< vector< int> >&mat,int n)
{

       if(i==n-1) //base case
             return mat[i][j];
//there is no out  of boundary case


  int down = mat[i][j]+f(i+1,j,mat,n);
  int diagonal = mat[i][j]+f(i+1,j+1,mat,n);

  return min(down, diagonal);


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

  cout<<f(0,0,mat,n)<<endl;

}





