
#include<bits/stdc++.h>

using namespace std;
int fun(int ind, int target, int a[],int n,vector<vector<int>> &dp)
{

    if (ind == n)
    {
        if (target == 0)
                return 0;

        return -1e9;
    }

    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    int pick = -1e9;
    if ( a[ind] <=target)
    {
        pick = 1 + fun(ind, target - a[ind], a,n,dp);
    }
    int notpick = fun(ind+1, target, a,n,dp);

    return dp[ind][target]= max(pick, notpick);

}
int main() {


int n=3,t;
cin>>t;
int arr[4];
 cin>>arr[0]>>arr[1]>>arr[2];

vector<vector<int>> dp(n + 1, vector<int>(t + 1, -1));
  int ans = fun(0, t, arr,3,dp);
    cout << ans << endl;

  return 0;
}

