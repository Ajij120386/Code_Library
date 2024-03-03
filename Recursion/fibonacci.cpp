#include<bits/stdc++.h>
using namespace std;

int  fibo(int ind)
{
         if(ind<=1)
            return ind;

       return fibo(ind-1)+fibo(ind-2);



}
int main(){

  int n;
  cin>>n;
  cout<<fibo(n)<<endl;

}



