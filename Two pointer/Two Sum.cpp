
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = make_pair(nums[i], i);
        }
        sort(arr.begin(), arr.end());
        int left = 0, right = n- 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target)

                 return {arr[left].second, arr[right].second};
            if (sum > target)
                right --; // Try to decrease sum2
            else
                left ++; // Try to increase sum2
        }
        return {};
    }
};
