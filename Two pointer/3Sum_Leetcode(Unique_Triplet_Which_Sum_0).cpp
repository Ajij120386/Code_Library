class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

         int n=nums.size();

     sort(nums.begin(),nums.end());
       vector<vector<int>>ans;

    for(int i=0;i<n;i++){

        if( i>0 && nums[i]==nums[i-1]) continue;

         int lo=i+1,hi=n-1;

          while(lo<hi)

       {

        long long int sum=nums[i]+nums[lo]+nums[hi];

        if(sum<0)

          lo++;

          else if(sum>0)

          hi--;

        else

        {
                       vector<int>tmp;
                       tmp.push_back(nums[i]);
                        tmp.push_back(nums[lo]);
                        tmp.push_back(nums[hi]);
                        ans.push_back(tmp);


                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;

                                lo++;
                        hi--;


        }





    }

     }


    return ans;

    }
};
