class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int>ans;

        map<int,int>mp;

        for(auto it: arr1)
         mp[it]++;

         for(auto it: arr2)
         {
             while(mp[it]!=0)
             {
                 ans.push_back(it);
                 mp[it]--;
             }

         }

         for(auto it:mp)
         {
            while(it.second!=0){

                ans.push_back(it.first);
                 it.second--;
            }
         }
         return ans;

    }
};
