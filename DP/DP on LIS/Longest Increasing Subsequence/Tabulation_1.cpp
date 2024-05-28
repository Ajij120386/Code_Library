
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

           int n=nums.size();
        vector< vector<int> > dp(n+1, vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int notTake= 0+dp[ind+1][prev+1];
                int Take=0;

                     if(prev==-1 || nums[ind]>nums[prev])

                            Take=1+dp[ind+1][ind+1];

                     dp[ind][prev+1]=max(Take,notTake);
            }
        }

        return dp[0][0];

    }
};
