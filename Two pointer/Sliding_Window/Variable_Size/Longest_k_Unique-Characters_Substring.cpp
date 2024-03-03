
class Solution{
  public:
    int longestKSubstr(string s, int k) {

   long long n=s.size(),j=0,i=0,mxlen=-1,sum=0;

   unordered_map<char,int>mp;

    while(j<n)
    {

        mp[s[j]]++;


        if(mp.size()<k)
              j++;

        else if(mp.size()==k)
         {

                mxlen=max(mxlen,j-i+1);
                j++;
         }
        else
        {

          while(mp.size()>k)
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
