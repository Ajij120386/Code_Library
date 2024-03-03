#include<bits/stdc++.h>
using namespace std;

int  fact(int ind)
{
         if(ind<=1)
            return 1;

       return ind*fact(ind-1);



}
int main(){

  int n;
  cin>>n;
  cout<<fact(n)<<endl;

}


