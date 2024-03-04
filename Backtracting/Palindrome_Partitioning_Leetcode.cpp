class Solution {
public:

int n;
 bool ispalindrome(string &s,int l,int r)
 {
       while(l<r){

           if(s[l]!=s[r])
           return false;
           l++;
           r--;
       }
       return true;
 }

   void func( int idx ,string &s, vector<string>&curr,vector<vector<string>>&ans ){



        if(idx==n){

                 ans.push_back(curr);
                 return ;

            }


   for(int i=idx;i<n;i++){

     if(ispalindrome(s,idx,i)){
            curr.push_back(s.substr(idx,i-idx+1));
            func(i+1,s,curr,ans);

            curr.pop_back();
        }

   }



    }
    vector<vector<string>> partition(string s) {


       n=s.size();
        vector<vector<string>>ans;

        vector<string>tmp;

         func(0,s,tmp,ans);
         return ans;
    }
};
