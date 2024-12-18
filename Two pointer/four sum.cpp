class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

         int n = nums.size();
    vector<vector<int>> ans;


    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {

        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int front = j + 1;
            int back = n - 1;
            while (front < back) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[front];
                sum += nums[back];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[front], nums[back]};
                    ans.push_back(temp);
                    front++; back--;

                    //skip the duplicates:
                    while (front < back && nums[front] == nums[front - 1]) front++;
                    while (front < back && nums[back] == nums[back + 1]) back--;
                }
                else if (sum < target) front++;
                else back--;
            }
        }
    }

    return ans;
}


};
