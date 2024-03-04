class Solution {
public:
    int triangleNumber(vector<int>& nums) {


          int n=nums.size();

     sort(nums.begin(),nums.end());
     int cnt=0;

    for(int i=n-1;i>=2;i--)
    {



         int lo=0,hi=i-1;

          while(lo<hi)

       {



        if(nums[lo]+nums[hi]>nums[i]){

                  cnt+=(hi-lo);

                  hi--;
        }

         else
             lo++;




     }





    }



    return cnt;

    }

};
