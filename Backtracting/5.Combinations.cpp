

/////******Approach-1***************



class Solution {
public:



     vector<vector<int>> res;
     vector<int>tmp;
   
   void f(int val,int n,int k)
   {
         
         if(k==0)
     {
          res.push_back(tmp);

          return;
     
      }
            
        
        for(int i=val;i<=n;i++)
        {
            

              tmp.push_back(i);
              f(i+1,n,k-1);
             tmp.pop_back();


        }
    
   }
  
    vector<vector<int>> combine(int n, int k) {

     
         
       f(1,n,k);

        return res;

    }
};




/////******Approach-2***************

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
