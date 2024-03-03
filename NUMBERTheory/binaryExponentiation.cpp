#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long power(long long base,long long x)
{
    long long result=1;
    while(x)
    {
        if(x%2==1)
        {
           result=((result%mod)*(base%mod))%mod;
           x--;
        }
        else
        {
            base=((base%mod)*(base%mod))%mod;
            x/=2;
        }
    }
      return result;
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<power(a,b)<<endl;
    }
}
