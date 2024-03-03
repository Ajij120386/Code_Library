#include <bits/stdc++.h>
using namespace std;

int f(int ind,string &s,vector<int>&dp) {

	if (ind <= 0)

            return 0;
	if(dp[ind] != -1)
	        return dp[ind];

	int take = 0;
	if ((s[ind] == 'y' && s[ind-1] == 'x') || (s[ind] == 'x' && s[ind-1] == 'y'))
             take = 1 + f(ind-2,s,dp);

	int nottake = 0+f(ind-1,s,dp);

	return dp[ind] = max(take, nottake);
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
    cin >> t;
    string s;
	while (t--)
    {

		cin >> s;
		int n=s.size();
		vector<int>dp(n+1, -1);

		cout <<f(n-1,s,dp) <<endl;
	}
}
