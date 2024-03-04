class Solution {
public:

   int n;
 set<vector<int>>result;

   void func(int ind,vector<int>&curr, vector<int>&nums,int T)
  {


    if(T==0)
     {
         result.insert(curr);
         return;
    }
 if(ind<0){

      return;
   }




     if(T>=nums[ind]){

          curr.push_back(nums[ind]);

            func(ind-1,curr,nums,T-nums[ind]);
            curr.pop_back();


     }


////Must Include This Line For Skipping Duplicate

     while(ind-1>=0 && nums[ind]==nums[ind-1]) ind--;

        func(ind-1,curr,nums,T);


  }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

       // unique(nums.begin(),nums.end());

       sort(nums.begin(),nums.end());

        n=nums.size();
        vector<int>tmp;
        func(n-1,tmp,nums,target);

        return vector(result.begin(),result.end());

    }
};
