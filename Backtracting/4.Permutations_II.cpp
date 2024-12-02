
class Solution {
public:


    vector<vector<int>> ans;
     vector<int>ds;
   unordered_map<int,int>mp;

   void f(int n, vector<int>&ar)
   {
       if(ds.size()==n)
       {

            ans.push_back(ds);

            return;
       }


     for(auto it: mp)
     {

         int key = it.first;
         int value = it.second;

            if(value == 0) continue;

            ds.push_back(key);
            mp[key]--;

                f(n,ar);

              ds.pop_back();
            mp[key]++;

         }


   }



    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();

       for(auto it: nums) mp[it]++;
        f(n,nums);
        return ans;
    }
};
