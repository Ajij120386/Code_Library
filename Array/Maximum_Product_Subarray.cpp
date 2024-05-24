
/*

Time complexity: O(n)
Space complexity: O(1)

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suf=1,pre=1,mx=INT_MIN;
      int n=nums.size();
         for(int i=0;i<n;i++)
         {
            if(suf==0) suf=1;
            if(pre==0) pre=1;

             suf*=(nums[n-i-1]);
              pre*=(nums[i]);
            mx=max(mx,max(suf,pre));

         }
        return mx;
    }
};
