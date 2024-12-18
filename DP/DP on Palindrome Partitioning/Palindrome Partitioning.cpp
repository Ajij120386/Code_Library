
class Solution {
public:


  int n;
   vector<vector<string>>res;


     bool isPalindrome(string &s,int l,int r)
     {

        while(l<r)
        {

            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;


     }

    void backtract(int ind,string &s,vector<string>&tmp)
    {

          //base case
          if(ind==n)
          {
            res.push_back(tmp);
            return;
          }

          for(int i=ind;i<n;i++)
          {

            if(isPalindrome(s,ind,i))
            {
                tmp.push_back(s.substr(ind,i-ind+1));
                 backtract(i+1,s,tmp);
                 tmp.pop_back();
            }

          }

    }


    vector<vector<string>> partition(string s)
    {
        n=s.size();
         vector<string>tmp;
        backtract(0,s,tmp);

        return res;
    }
};
