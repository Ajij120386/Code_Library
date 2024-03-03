class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
{

      unordered_map<long long,int>mp;
    long long sum =0;
    int cnt=0;
    mp[0]=1;

    for(int i=0;i<nums.size();i++)
    {

          sum+=nums[i];

       long long rem=sum%k;

       //negative reminder handle
        if(rem<0)
               rem+=k;

      //if(mp.find(rem)!=mp.end())
                         cnt+=mp[rem];

            mp[rem] += 1;



    }
    return cnt;

 }
};
