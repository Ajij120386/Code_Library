
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {


	     unordered_map<char,int>mp;
        for(auto it: p)
        {
          mp[it]++;
        }

     int cnt=mp.size();
     vector<int>ans;

     int i=0,j=0,n=s.size(),k=p.size();

      while(j<n)
     {

          if(mp.find(s[j])!=mp.end())
          {

              mp[s[j]]--;

              if(mp[s[j]]==0) cnt--;
          }

         if(j-i+1<k) j++;

         else
         {

               if(cnt==0)  ans.push_back(i);

                if(mp.find(s[i])!=mp.end())
               {
                  mp[s[i]]++;

                if(mp[s[i]]==1) cnt++;

               }

           j++,i++;

         }


      }
      return ans;
    }
};
