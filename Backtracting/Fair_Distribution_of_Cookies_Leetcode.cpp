class Solution {
public:

int n,res=INT_MAX;
   void func(int ind,vector<int>&nums,vector<int>&child,int k)
   {

       if(ind==n){

           int unfair=*max_element(begin(child),end(child));

           res=min(res,unfair);
           return;
       }

       int val=nums[ind];

              for(int i=0;i<k;i++)
            {
               child[i]+=val;
               func(ind+1,nums,child,k);
               child[i]-=val;

             }

   }

    int distributeCookies(vector<int>& cookies, int k) {

        n=cookies.size();
        vector<int>child(k);

        func(0,cookies,child,k);
        return res;


    }
};
