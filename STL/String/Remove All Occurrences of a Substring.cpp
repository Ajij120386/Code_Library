
class Solution {
public:
    string removeOccurrences(string s, string part) {


        string ans;

        for(auto it: s)
        {

             ans.push_back(it);

             if(ans.size()>=part.size() && ans.substr( ans.size()-part.size() ) == part )
           {

                  int x=part.size();
                  while(x--)
                  {
                    ans.pop_back();
                  }


           }


        }
        return ans;
    }
};
