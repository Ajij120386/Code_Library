class Solution {
public:

   int n;
    vector<vector<int>>result;

   void func(int ind,vector<int>&curr, vector<int>&nums,int T)
  {


    if(T==0)
     {
         result.push_back(curr);
         return;
     }
 if(ind<0){

      return;
   }




     if(T>=nums[ind]){

          curr.push_back(nums[ind]);

            func(ind,curr,nums,T-nums[ind]);
            curr.pop_back();


     }




        func(ind-1,curr,nums,T);


  }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

          n=nums.size();
        vector<int>tmp;
        func(n-1,tmp,nums,target);
        return result;


    }
};
