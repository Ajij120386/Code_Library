class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {


    unordered_map<long long,int>mp;
    long long psum =0;
    int cnt=0;
    mp[0]=1;

    for(int i=0;i<nums.size();i++)
  {

          psum+=nums[i];




    long long rem=psum%k;

    cnt+=mp[rem];

        mp[psum] += 1;



 }
    return cnt;

    }
};
