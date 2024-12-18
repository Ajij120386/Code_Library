
class Solution {
public:


  int n;



     bool isPalindrome(string &s,int l,int r)
     {

        while(l<r)
        {

            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;


     }

    int f(int ind,string &s, vector<int>&dp)
    {

          //base case
          if(ind==n)
          {

            return 0;
          }

          if(dp[ind]!=-1) return dp[ind];

         int mnCost= INT_MAX;

          for(int i=ind;i<n;i++)
          {

            if(isPalindrome(s,ind,i))
            {
                int cost= 1+f(i+1,s,dp);

               mnCost= min(mnCost,cost);

            }

          }

        return dp[ind]=mnCost;
    }



    int minCut(string s) {

         n=s.size();

       vector<int>dp(n,-1);

           return f(0,s,dp)-1;


    }
};
