
class Solution {
public:
    string minWindow(string s, string t) {


        unordered_map<char,int>mp;
        for(auto ch :t) mp[ch]++;
        int cnt=mp.size();

        int i=0,n=s.length(),j=0,mnlen=INT_MAX,start=0;

        while(j<n)
        {
           if(mp.find(s[j])!=mp.end())
           {
              mp[s[j]]--;
              if( mp[s[j]]==0) cnt--;

           }


           if(cnt==0)
           {
               while(cnt==0)
               {
                  if(mp.find(s[i])!=mp.end())
                 {
                        mp[s[i]]++;
                     if( mp[s[i]]==1)
                     {
                          cnt++;
                        if(j-i+1<mnlen)
                        {
                            start=i;
                            mnlen=j-i+1;
                        }
                     }

                }
                i++;
               }
           }

                j++;
        }


     if(mnlen==INT_MAX)
              return "";
      return s.substr(start,mnlen);

    }
};
