
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

	     unordered_map<char,int>mp;
        for(auto it: s1)
        {
          mp[it]++;
        }

     int cnt=mp.size(),ans=0;

     int i=0,j=0,n=s2.size(),k=s1.size();

      while(j<n)
     {
          ///DO
          if(mp.find(s2[j])!=mp.end())
          {

              mp[s2[j]]--;

              if(mp[s2[j]]==0) cnt--;
          }

         if(j-i+1<k) j++;

         else
         {

               if(cnt==0)
               {
                  return true;

               }

             //UNDO
                if(mp.find(s2[i])!=mp.end())
               {
                  mp[s2[i]]++;

                if(mp[s2[i]]==1) cnt++;

               }

           j++,i++;

         }


      }
      return false;

    }
};
