
/*

   Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.


*/


class Solution {
public:


   vector<vector<int>>result;

   int dp[201][1001];
   int n;
   int solve(int ind, vector<int>& nums, int T) {

        if(T==0) {
           return 1;

        }

       if(ind>=n || T<0){
        return 0;
       }

      if(dp[ind][T]!=-1)

      return dp[ind][T];

          int take= solve(0, nums,T-nums[ind]);
         int  nottake= solve(ind+1, nums,T);

        return  dp[ind][T]= take+nottake;


    }
    int combinationSum4(vector<int>& nums, int target)
    {
        n=nums.size();
        memset(dp,-1,sizeof(dp));

         return solve(0,nums,target);
    }
};
