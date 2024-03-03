
//1st Solution


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        long long n=s.size(),j=0,i=0,mxlen=0,sum=0;

   unordered_map<char,int>mp;

    while(j<n)
    {

        mp[s[j]]++;



        if(mp[s[j]]==1)
         {

                mxlen=max(mxlen,j-i+1);
                j++;
         }
        else
        {

          while(mp[s[j]]>1)
          {

             mp[s[i]]--;



              i++;

          }
         j++;
        }

     }
    return mxlen;
    }
};


//2nd Solution


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        long long n=s.size(),j=0,i=0,mxlen=0,sum=0;

   unordered_map<char,int>mp;

    while(j<n)
    {

        mp[s[j]]++;



        if(mp.size()==j-i+1)
         {

                mxlen=max(mxlen,j-i+1);
                j++;
         }
        else
        {

          while(mp.size()<j-i+1)
          {

             mp[s[i]]--;

              if( mp[s[i]]==0)
                 mp.erase(s[i]);

              i++;

          }
         j++;
        }

     }
    return mxlen;
    }
};
