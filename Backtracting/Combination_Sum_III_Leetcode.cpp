/*
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.


/********************   Approach_1      *****************************

*/

class Solution {
public:

     vector<vector<int>>result;

   void func(int ind,vector<int>&curr, vector<int>&nums,int T,int k)
  {

  if(curr.size()==k){

    if(T==0)
     {
         result.push_back(curr);
      }
     return;
  }

    if(ind<0) return;


     if(T>=nums[ind]){

          curr.push_back(nums[ind]);

            func(ind-1,curr,nums,T-nums[ind],k);
         curr.pop_back();


     }

        func(ind-1,curr,nums,T,k);


  }

    vector<vector<int>> combinationSum3(int k, int n) {


         vector<int>nums{1,2,3,4,5,6,7,8,9};

        vector<int>tmp;
        func(8,tmp,nums,n,k);
        return result;

    }
};

/********************   Approach_2      ******************************/

class Solution {
public:

     vector<vector<int>>result;

   void func(int ind,vector<int>&curr,int T,int k)
  {

  if(curr.size()==k){

    if(T==0)
     {
         result.push_back(curr);
      }
     return;
  }


    for(int i=ind;i<=9;i++)
    {
          if(T>=i){

          curr.push_back(i);
      func(i+1,curr,T-i,k);
         curr.pop_back();


     }

    }





  }

    vector<vector<int>> combinationSum3(int k, int n) {




        vector<int>tmp;
        func(1,tmp,n,k);
        return result;

    }
};
