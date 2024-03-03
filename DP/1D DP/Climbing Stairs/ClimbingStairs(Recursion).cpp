#include<bits/stdc++.h>
using namespace std;

int  f(int ind)
{
         if(ind==0) return 1;

         if(ind==1) return 1;

       return f(ind-1)+f(ind-2);



}
int main(){

  int n;
  cin>>n;
  cout<<f(n)<<endl;

}

