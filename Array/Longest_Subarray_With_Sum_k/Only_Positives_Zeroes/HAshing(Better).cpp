
//TC: 0(N)
//SC: 0(N)

#include <bits/stdc++.h>
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here


    unordered_map<long long,int>mp;
    long long psum =0;
    int mxlen=0;
    for(int i=0;i<nums.size();i++)
  {

          psum+=nums[i];

   if(psum==k)
          mxlen=max(mxlen,i+1);


    long long rem=psum-k;

    if(mp.find(rem)!=mp.end())
    {
        int len=i-mp[rem];
        mxlen=max(mxlen,len);
    }

    if (mp.find(psum) == mp.end())
     {
        mp[psum] = i;
     }


 }
    return mxlen;
}

