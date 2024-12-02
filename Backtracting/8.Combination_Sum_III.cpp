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

    
     vector<vector<int>> res;
     vector<int>tmp;
   
   void f(int val,int  T, int k)
   {
         

         if(T<0 || tmp.size()>k return;
         
         if(k==0 && T==0)
     {
          res.push_back(tmp);

          return;
     
      }
            
        
        for(int i=val;i<=9;i++)
        {
            

              tmp.push_back(i);
              f(i+1,T-i,k-1);
             tmp.pop_back();


        }
    
   }
  
    vector<vector<int>> combinationSum3(int k, int n) {

        f(1,n,k);
        return res;
        
    }
};