

/*
    Given an array of positive integers nums and a positive integer target, return the minimal length of a
     subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;

        int sum = 0;
        int minL = n+1;

        while(j < n) {
            sum += nums[j];

            while(sum >= target) {
                minL = min(minL, j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }
        return minL == n+1 ? 0 : minL;
    }
};
