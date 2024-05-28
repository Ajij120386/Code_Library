
class Solution {
public:
   int f(int ind,vector<int>& prices,int n,int buy,vector< vector<int> >&dp)
   {

     if(ind>=n)
     return 0;

     if(dp[ind][buy]!=-1)
       return dp[ind][buy];

     int profit=0;
     if(buy==0)
     {
         profit=max(   0+f(ind+1,prices,n,0,dp),
                    -prices[ind]+f(ind+1,prices,n,1,dp) );
     }
     else{

           profit=max(   0+f(ind+1,prices,n,1,dp),
                    prices[ind]+f(ind+2,prices,n,0,dp) );
     }
       return  dp[ind][buy]= profit;
   }
    int maxProfit(vector<int>& prices) {

      int n=prices.size();

     vector< vector<int> >dp(n,vector<int>(2,-1));
       return f(0,prices,n,0,dp);

    }
};
