
class Solution {
public:

int n;
int f(int ind,int k, vector<int>&num,  vector<int>&dp)
    {

          //base case
          if(ind==n)
          {

            return 0;
          }

          if(dp[ind]!=-1) return dp[ind];

       int len = 0;
      int maxi = INT_MIN;
       int maxAns = INT_MIN;

          for(int i=ind;i<min(ind+k,n);i++)
          {
             len++;

             maxi = max(maxi, num[i]);
             int sum = len * maxi + f(i + 1, k,num, dp);
             maxAns = max(maxAns, sum);

          }

        return dp[ind]= maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

      n=arr.size();

       vector<int>dp(n,-1);

           return f(0,k,arr,dp);

    }
};
