#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

    int n=nums.size();
     int mindiff=100000,ans=0;
     sort(nums.begin(),nums.end());


    for(int i=0;i<n;i++){



         int lo=i+1,hi=n-1;

          while(lo<hi)

       {

        int sum=nums[i]+nums[lo]+nums[hi];

        if(sum==target) return sum;
        else if( abs(sum-target)<mindiff)
        {
            mindiff=abs(sum-target);
            ans=sum;
        }
       else if(sum>target)

          hi--;

        else
          lo++;


        }





    }




    return ans;

    }
};
