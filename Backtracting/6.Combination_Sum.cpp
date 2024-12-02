
////////////////////////////////USING FOR LOOP

class Solution {
public:


   vector<vector<int>>ans;
  void f( int ind,vector<int>&tmp, vector<int>&nums,int n,int t)
   {

if (t<0) return;

     // if (ind<0) return;

     if(t==0){

            ans.push_back(tmp);

            return;

     }


       for(int i=ind;i<n;i++)
       {


                 tmp.push_back(nums[i]);
               f(i,tmp,nums,n,t-nums[i]);
                tmp.pop_back();





       }

   }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

    vector<int>tmp;

   int n=nums.size();
      f(0,tmp,nums,n,target);

        return ans;
    }
};

/////////////////////////////////USING PICK NOT PICK (BOTTOM UP)
class Solution {
public:


   vector<vector<int>>ans;
  void f( int ind,vector<int>&tmp, vector<int>&nums,int n,int t)
{


    if(ind==n){

           if(t==0)
            ans.push_back(tmp);

            return;
       }




                f(ind+1,tmp,nums,n,t);

                  if(nums[ind]<=t)
             {
                 tmp.push_back(nums[ind]);

                f(ind,tmp,nums,n,t-nums[ind]);
                tmp.pop_back();
             }


   }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

    vector<int>tmp;

   int n=nums.size();
      f(0,tmp,nums,n,target);

        return ans;
    }
};

////////////////////////////TOP down
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
