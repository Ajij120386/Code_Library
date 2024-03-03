
/*
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

*/


#include<bits/stdc++.h>

using namespace std;

    void func(int ind, vector < int > &ds, int arr[],int n)
     {
         if (ind == n)
            {
                 for(auto it: ds){
                    cout<<it<<" ";
                 }
                 cout<<endl;
                  return;
            }
      //element is picked
      ds.push_back(arr[ind]);
      func(ind + 1, ds,arr, n);

      //element is not picked
           ds.pop_back();

           func(ind + 1, ds,arr, n);
    }


int main() {

   int arr[] = {1,3,2};
 vector<int>ds;

    func(0,ds,arr,3);


  return 0;
}
