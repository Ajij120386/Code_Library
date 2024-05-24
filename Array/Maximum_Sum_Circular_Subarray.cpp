class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

         int mx=nums[0],mn=nums[0];
        int  s1=nums[0],s2=nums[0];
       int totalsum= accumulate(begin(nums),end(nums),0);

        for(int i=1;i<nums.size();i++)
        {

             s1=max(nums[i],s1+nums[i]);
             s2=min(nums[i],s2+nums[i]);

             mx=max(mx,s1);
              mn=min(mn,s2);

        }
     int circsum=totalsum-mn;
     if(mx>0) return max(circsum,mx);
     return mx;

    }
};
