#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;

    int prev=1;
   int prev2=1;

 for(int i=2;i<=n;i++){

        int cur= prev2+prev;
         prev2=prev;
         prev=cur;
 }
   cout<<prev<<endl;
}
