

//Problem_1              max-sum-subarray-of-size-k

class Solution{
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here

        int n=N;
        long long i=0,j=0,sum=0,res=INT_MIN;
        while(j<n)
        {
             sum+=Arr[j];
             if(j-i+1<K)
                 j++;
              else{

                  res=max(res,sum);
                  sum-=Arr[i];
                  i++;
                  j++;
              }


        }
        return res;

    }
};



///Problem_2 maximum-sum-of-distinct-subarrays-with-length-k
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<long long,int>mp;
        long long i=0,j=0,sum=0,res=0,cnt=0;
        while(j<n)
        {
            if(mp[nums[j]]==0)
            {
                     cnt++;
            }
            mp[nums[j]]++;
             sum+=nums[j];
             if(j-i+1<k)
                 j++;
              else{



                      if(cnt==k){
                          res=max(res,sum);

                      }
                  mp[nums[i]]--;
                        if(mp[nums[i]]==0) cnt--;

                  sum-=nums[i];
                  i++,j++;
              }


        }
        return res;

    }
};
