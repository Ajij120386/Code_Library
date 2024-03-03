#include<bits/stdc++.h>
using namespace std;
int dp[5000];
int a,b,c;
int DP(int n)
{
    if(n==0)
        return 0;
    if(n<0)
        return -10000;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=max(1+DP(n-a),max(1+DP(n-b),1+DP(n-c)));
}
int main()
{
    vector<int> v;
    int d,x,y,z,i,j,k,n;
    cin>>n;
    cin>>a>>b>>c;
    for(x=0;x<4010;x++)
        dp[x]=-1;
    cout<<DP(n)<<endl;
}
