
class Solution {
public:

bool static cmp(pair<char,int>a, pair<char,int>b){


            return a.second>b.second;

        }

    string frequencySort(string s) {




        unordered_map<char,int>mp;

        for(auto it: s)
        {
            mp[it]++;
        }

        vector< pair<char,int> >vec;
         for(auto it: mp)
        {
            vec.push_back(it);
        }


        sort(vec.begin(),vec.end(),cmp) ;

                string ans;

          for(int i=0;i<vec.size();i++)
          {
            /*
              while(vec[i].second>0)
              {
                  ans.push_back(vec[i].first);
                  vec[i].second--;
              }
              */

              if(vec[i].second>0)
              {
                char ch= vec[i].first;
                int freq=vec[i].second;
                string tmp= string(freq,ch);
                ans+=tmp;
              }
          }
          return ans;

    }
};
