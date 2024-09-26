
///////////////////////////////USING FOR LOOP

class Solution {
public:

  vector<vector<int>>ans;
  void f( int ind,vector<int>&tmp, vector<int>&nums,int n,int t)
   {


     if (ind<0) return;
     if(t==0){

            ans.push_back(tmp);

            return;

     }


       for(int i=ind;i<n;i++)
       {

            if(i!=ind && nums[i]==nums[i-1]) continue;


                 tmp.push_back(nums[i]);
               f(i+1,tmp,nums,n,t-nums[i]);
                tmp.pop_back();

       }

   }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {


       sort(nums.begin(),nums.end());
      vector<int>tmp;

      int n=nums.size();
      f(0,tmp,nums,n,target);

        return ans;

    }
};

/////USING PICK & NOT PICK TECHNIQUE BOTTOM_UP

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





                  if(nums[ind]<=t)
             {
                 tmp.push_back(nums[ind]);

                f(ind+1,tmp,nums,n,t-nums[ind]);
                tmp.pop_back();
             }
       while(ind+1<n && nums[ind]==nums[ind+1]) ind++;
                f(ind+1,tmp,nums,n,t);

   }









    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {


       sort(nums.begin(),nums.end());
      vector<int>tmp;

      int n=nums.size();
      f(0,tmp,nums,n,target);

        return ans;

    }
};


////////////////
/////USING PICK & NOT PICK TECHNIQUE UP DOWN


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
