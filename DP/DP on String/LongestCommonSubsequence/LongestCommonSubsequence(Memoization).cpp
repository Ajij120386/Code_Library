#include <bits/stdc++.h>

using namespace std;

int LCS(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){

    if(ind1<0 || ind2<0)
        return 0;

    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + LCS(s1,s2,ind1-1,ind2-1,dp);

    else
        return dp[ind1][ind2] = 0 + max(LCS(s1,s2,ind1,ind2-1,dp),LCS
       (s1,s2,ind1-1,ind2,dp));

}


int main() {

  string s1= "acd";
  string s2= "ced";

   int n=s1.size();
   int m=s2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<LCS(s1,s2,n-1,m-1,dp)<<endl;
}
