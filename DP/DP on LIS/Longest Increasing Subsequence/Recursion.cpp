
class Solution {
public:

    int f(int ind,int prev,vector<int>& nums)
    {

         if(ind==nums.size())
            return 0;

         int notTake=0+f(ind+1,prev,nums);
         int Take=0;
         if(prev==-1 || nums[ind]>nums[prev])

           Take=1+f(ind+1,ind,nums);

           return max(Take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {

        return f(0,-1,nums);
    }
};
