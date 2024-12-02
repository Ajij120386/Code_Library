
/////////////////////////////USING FOR LOOP

class Solution {
public:



 vector<vector<int>>ans;
  void f( vector<int>&tmp, vector<int>&nums,int ind,int n)
   {

          ans.push_back(tmp);

       for(int i=ind;i<n;i++)
       {

           tmp.push_back(nums[i]);
           f(tmp,nums,i+1,n);
           tmp.pop_back();


       }

   }


    vector<vector<int>> subsets(vector<int>& nums) {



    vector<int>tmp;

   int n=nums.size();
      f(tmp,nums,0,n);

        return ans;

    }
};


/////////////////////////////USING PICK  NOT PICK TECHNIQUE
class Solution {
public:


   void f(int ind,vector<int>&ar, vector<int>&ds, vector< vector<int > >&ans)
   {
       if(ind<0){
            ans.push_back(ds);
              return;
       }

              //not pick it
           f(ind-1,ar,ds,ans);

             //pick it
           ds.push_back(ar[ind]);
            f(ind-1,ar,ds,ans);
               ds.pop_back();

   }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector< vector<int > >ans;
        vector<int>ds;

        int n=nums.size();
         f(n-1,nums,ds,ans);

         return ans;
    }
};

/////NOT SENDING REFERENCE ONLY USING RECURSIVE function

class Solution {
public:


   void f(int ind,vector<int>&ar, vector<int>ds, vector< vector<int > >&ans)
   {
       if(ind<0){
            ans.push_back(ds);
              return;
       }

              //not pick it
           f(ind-1,ar,ds,ans);

             //pick it
           ds.push_back(ar[ind]);
            f(ind-1,ar,ds,ans);


   }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector< vector<int > >ans;
        vector<int>ds;

        int n=nums.size();
         f(n-1,nums,ds,ans);

         return ans;
    }
};
