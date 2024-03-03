#include<bits/stdc++.h>
using namespace std;
#define int long long int

int trailingzero(int n){

int s=0;
 while(n/5>0)
{

  s+=(n/5);
   n/=5;


}
return s;


}
int32_t main(){
    int n;
    cin>>n;

    cout<<trailingzero(n)<<endl;
return 0;
}
