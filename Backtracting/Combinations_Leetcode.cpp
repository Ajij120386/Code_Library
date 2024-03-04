class Solution {
public:

  void func(int ind,vector<int>&curr,vector<vector<int>>&ans,int n,int k)
  {


     if(k==0)
     {
         ans.push_back(curr);

          return;

      }
    if(ind>n) return;



            curr.push_back(ind);

            func(ind+1,curr,ans,n,k-1);
             curr.pop_back();

              func(ind+1,curr,ans,n,k);


  }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>>ans;
        vector<int>tmp;
        func(1,tmp,ans,n,k);
        return ans;
    }
};
