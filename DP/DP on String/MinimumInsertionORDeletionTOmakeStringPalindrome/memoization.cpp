

class Solution {
public:

          int lcs(string &s1, string &s2,int ind1,int ind2, vector< vector<int> >&dp)
   {

     if(ind1<0 || ind2<0)
      return 0;

      if(dp[ind1][ind2]!=-1)
                return dp[ind1][ind2];
       if(s1[ind1]==s2[ind2])
                    return dp[ind1][ind2]=1+lcs(s1,s2,ind1-1,ind2-1,dp);
        else
             return  dp[ind1][ind2]=0+max(lcs(s1,s2,ind1-1,ind2,dp),lcs(s1,s2,ind1,ind2-1,dp));



   }
    int minInsertions(string s) {
         int n=s.size();

        string temp=s;
        reverse(temp.begin(),temp.end());

         vector< vector<int> >dp(n,vector<int>(n,-1));
        return n-lcs(s,temp,n-1,n-1,dp);
    }
};