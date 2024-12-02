
//////*****************Approach1------------***********
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

//////*****************Approach2------------***********

class Solution {
public:


   vector<vector<int>> res;
     vector<int>tmp;
   
   void f(int ind,int n,vector<int>& nums)
   {
         
         if(ind==n){
            res.push_back(tmp);
            return ;
         }

      tmp.push_back(nums[ind]);

      f(ind+1,n,nums);
      tmp.pop_back();

    // for duplicate ccheck
       while(ind+1<n && nums[ind]==nums[ind+1]) ind++;
      f(ind+1,n,nums);

   }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

      int n=nums.size();

      sort(nums.begin(),nums.end());
         
       f(0,n,nums);

        return res;
    }

    
};