
class Solution {
public:

    int f(int ind,int prev,vector<int>& nums, vector< vector<int> > &dp)
    {

         if(ind==nums.size())
            return 0;
         //Applying Coordinate Shifting
         if(dp[ind][prev+1]!=-1)
               return dp[ind][prev+1];

         int notTake=0+f(ind+1,prev,nums,dp);
         int Take=0;
         if(prev==-1 || nums[ind]>nums[prev])

           Take=1+f(ind+1,ind,nums,dp);

           return dp[ind][prev+1]=max(Take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector< vector<int> > dp(n+1, vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};
