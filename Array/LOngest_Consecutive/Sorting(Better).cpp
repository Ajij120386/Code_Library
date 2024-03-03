
//TC: 0(NLogN)+0(N)
//SC: 0(1)



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int leftsmaller=INT_MIN, mxlen=0,cnt=0;

        for(auto it: nums){

        if(it-1==leftsmaller){

            cnt+=1;
            leftsmaller=it;
        }
        else if(it!=leftsmaller){

            cnt=1;
             leftsmaller=it;
        }

            mxlen=max(cnt,mxlen);

      }

        return mxlen;
    }
};
