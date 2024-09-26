
class Solution {
public:


     vector<vector<int>>ans;
  void f( vector<int>&tmp, vector<int>&nums,int ind,int n)
   {

          ans.push_back(tmp);

       for(int i=ind;i<n;i++)
       {
          if(i!=ind && nums[i]==nums[i-1]) continue; //for duplicate check

           tmp.push_back(nums[i]);
           f(tmp,nums,i+1,n);
           tmp.pop_back();


       }

   }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

     vector<int>tmp;
     sort(nums.begin(),nums.end());
   int n=nums.size();
      f(tmp,nums,0,n);

        return ans;

    }
};
