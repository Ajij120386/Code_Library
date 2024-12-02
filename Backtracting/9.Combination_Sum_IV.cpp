
//******************Approach-1 Using For LOOP****************


class Solution {
public:


   vector<vector<int>>result;

   int dp[1001];
   int n;
   int solve(vector<int>& nums, int T) {

        if(T==0) {
           return 1;

        }

       if( T<0){
        return 0;
       }

      if(dp[T]!=-1)

      return dp[T];

int res=0;
    for(int i=0;i<n;i++)
    {
         int take= solve(nums,T-nums[i]);
         res+=take;
    }


        return  dp[T]= res;


    }
    int combinationSum4(vector<int>& nums, int target)
    {
        n=nums.size();
        memset(dp,-1,sizeof(dp));

         return solve(nums,target);
    }
};
//******************Approach-2  Using Pick not pick****************


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
