
/******************************Approach 1 ( USING SET )***************************/

class Solution {
public:


    unordered_set<int>st;
   void f(int n, vector<int>&ds,vector< vector<int > >&ans,vector<int>&ar)
   {
       if(ds.size()==n)
       {

            ans.push_back(ds);

            return;
       }


     for(int i=0;i<n;i++)
     {
            if(st.find(ar[i])==st.end())
         {
              ds.push_back(ar[i]);
              st.insert(ar[i]);
              f(n,ds,ans,ar);
               st.erase(ar[i]);
              ds.pop_back();
         }
     }

   }

    vector<vector<int>> permute(vector<int>& nums) {

        vector< vector<int > >ans;
        vector<int>ds;

       int n=nums.size();


        f(n,ds,ans,nums);
        return ans;

    }
};

/******************************Approach 2  USING FREQUENCY ) ***********************/
class Solution {
public:


   void f(int n, vector<int>&ds,vector< vector<int > >&ans,vector<int>&ar,vector<int>&freq)
   {
       if(ds.size()==n)
       {

            ans.push_back(ds);

            return;
       }


     for(int i=0;i<n;i++)
     {

         if(freq[i]==0){
             ds.push_back(ar[i]);
              freq[i]=1;
              f(n,ds,ans,ar,freq);
              freq[i]=0;
              ds.pop_back();
         }
     }

   }

    vector<vector<int>> permute(vector<int>& nums) {

        vector< vector<int > >ans;
        vector<int>ds;

       int n=nums.size();
        vector<int>freq(nums.size(),0);

        f(n,ds,ans,nums,freq);
        return ans;

    }
};
