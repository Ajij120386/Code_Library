#include <bits/stdc++.h>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here

   long long n=a.size(),j=0,i=0,mxlen=0,sum=0;

    while(j<n)
    {
        sum+=a[j];

        if(sum<k)
              j++;

        else if(sum==k)
         {
                mxlen=max(mxlen,j-i+1);
                j++;
         }
        else
        {

          while(sum>k)
          {
              sum-=a[i];
              i++;

             if(sum==k)
               mxlen=max(mxlen,j-i+1);
          }
         j++;
        }

     }
    return mxlen;
}
