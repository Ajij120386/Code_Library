class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow=nums[0];
        int fast=nums[0];

        slow=nums[slow];  //jump one time
        fast=nums[nums[fast]]; //jump two time


    //detect Cycle
        while(slow!=fast)
        {
            slow=nums[slow];  //jump one time
          fast=nums[nums[fast]]; //jump two time
        }

       //find starting point of loop which is surely duplicate

       slow=nums[0];
         while(slow!=fast)
        {
            slow=nums[slow];  //jump one time
            fast=nums[fast]; //jump one time
        }

  return fast;

    }
};
