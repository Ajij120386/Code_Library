
//TC: 0(N)
//SC: 0(N)

int lenOfLongSubarr(int A[],  int N, int K)
    {

        unordered_map<int,int>mp;

          int s=0,mxlen=0;

           for(int i=0;i<N;i++)
           {
              s+=A[i];

               if(s==K)
               {
                   mxlen=max(mxlen,i+1);
               }
               int rem=s-K;

               if(mp.find(rem)!=mp.end())
               {
                     int len=i-mp[rem];
                     mxlen=max(mxlen,len);
               }

               //Edge Case, So dangerous
               if(mp.find(s)==mp.end())
                      mp[s]=i;
           }

      return mxlen;
    }

