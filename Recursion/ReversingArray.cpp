#include<bits/stdc++.h>
using namespace std;

void  reversingArray(int i,int ar[] ,int n)
{
       if(n/2<=i) return;

   swap(ar[i],ar[n-i-1]);
 return  reversingArray(i+1,ar,n);



}
int main(){

  int n;
  cin>>n;
  int ar[n+1];
  for(int i=0;i<n;i++) cin>>ar[i];

  reversingArray(0,ar,n);
   for(int i=0;i<n;i++) cout<<ar[i]<<" ";
   cout<<endl;


}



