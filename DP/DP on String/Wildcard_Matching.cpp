class Solution {
public:


bool isAllStars(string &s1,int ind)
{
    for(int i=0;i<=ind;i++)
    {
        if(s1[i]!='*')
        return false;
    }
    return true;
}

  bool f(int ind1,int ind2,string &s, string &p,vector< vector<int> >&dp)
{

  if(ind1<0 && ind2<0) return true;
  if(ind1>=0 && ind2<0) return false;
  if(ind2>=0 && ind1<0) return isAllStars(p,ind2);

  if(ind1<0) return ind2+1;

  if(dp[ind1][ind2]!=-1)
      return dp[ind1][ind2];




  if(s[ind1]==p[ind2] || p[ind2]=='?'){

    return dp[ind1][ind2]=f(ind1-1,ind2-1,s,p,dp);

  }

  else{

      if( p[ind2]=='*'){

    return dp[ind1][ind2]=f(ind1-1,ind2,s,p,dp) || f(ind1,ind2-1,s,p,dp);

  }
  else
    return false;
  }





}

    bool isMatch(string s, string p) {

        int n=s.size();
         int m=p.size();

        vector< vector<int> > dp(n+1,vector<int>(m+1,-1));

        return f(n-1,m-1,s,p,dp) ;


    }
};
