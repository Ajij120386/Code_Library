/*
   Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]

    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]
*/

class Solution {
public:

   void f(int ind,int T,vector<int>&ar, vector<int>&ds,vector< vector<int > >&ans)
   {
       if(ind<0){
           if(T==0)
            ans.push_back(ds);

            return;
       }

      f(ind-1,T,ar,ds,ans);

        if(ar[ind]<=T)
       {
           ds.push_back(ar[ind]);

               f(ind,T-ar[ind],ar,ds,ans);
               ds.pop_back();
        }
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector< vector<int > >ans;
        vector<int>ds;

        int n=candidates.size();
         f(n-1,target,candidates,ds,ans);

         return ans;
    }
};
