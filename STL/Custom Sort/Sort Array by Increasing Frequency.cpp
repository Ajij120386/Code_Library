
class Solution {
public:

bool static cmp(pair<int,int>a, pair<int,int>b){


 // If multiple values have the same frequency, sort them in decreasing order.
        if(a.second==b.second)
         return a.first>b.first;

   // sort the array in increasing order based on the frequency of the values.
         else

            return a.second<b.second;

        }
    vector<int> frequencySort(vector<int>& nums) {



        unordered_map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]++;
        }

        vector<pair<int,int> >vec;
         for(auto it: mp)
        {
            vec.push_back(it);
        }


        sort(vec.begin(),vec.end(),cmp) ;

          vector<int>ans;
          for(int i=0;i<vec.size();i++)
          {
              while(vec[i].second>0)
              {
                  ans.push_back(vec[i].first);
                  vec[i].second--;
              }
          }
          return ans;
    }

};
