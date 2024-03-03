
int search(string pat, string txt) {
	    // code here


	     unordered_map<char,int>mp;
        for(auto it: pat)
        {
          mp[it]++;
        }

     int cnt=mp.size(),ans=0;

     int i=0,j=0,n=txt.size(),k=pat.size();

      while(j<n)
     {

          if(mp.find(txt[j])!=mp.end())
          {

              mp[txt[j]]--;

              if(mp[txt[j]]==0) cnt--;
          }

         if(j-i+1<k) j++;

         else
         {

               if(cnt==0)  ans++;

                if(mp.find(txt[i])!=mp.end())
               {
                  mp[txt[i]]++;

                if(mp[txt[i]]==1) cnt++;

               }

           j++,i++;

         }


      }
      return ans;

	}
