


   class Solution {
public:

int f(int ind1,int ind2,string &s, string &t,vector< vector<int> >&dp)
{

  if(ind2<0) return ind1+1;
  if(ind1<0) return ind2+1;

  if(dp[ind1][ind2]!=-1)
      return dp[ind1][ind2];




  if(s[ind1]==t[ind2]){

    return dp[ind1][ind2]=f(ind1-1,ind2-1,s,t,dp);

  }

  else{

       return dp[ind1][ind2]=1+min( f(ind1,ind2-1,s,t,dp),min( f(ind1-1,ind2,s,t,dp) ,f(ind1-1,ind2-1,s,t,dp) ) );
  }



    return dp[ind1][ind2];

}
    int minDistance(string word1, string word2) {

         int n=word1.size();
         int m=word2.size();

        vector< vector<int> > dp(n+1,vector<int>(m+1,-1));

        return f(n-1,m-1,word1,word2,dp) ;

    }
};
