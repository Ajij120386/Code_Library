
class Solution {
public:

    //Total count of subarrays having <= k distict elements

    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n = nums.size();
        int i = 0;
        int j = 0;

        int count = 0;

        while(j < n) {

            mp[nums[j]]++;

            while(mp.size() > k) {
                //shrink the window
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += (j-i+1); //ending at j
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};
