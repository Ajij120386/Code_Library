
//TC: 0(N)+0(2*N)
//SC: 0(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>st;
        for(auto it: nums)
        {
            st.insert(it);

        }
        int mxlen=0;
        for(auto it: nums){

      if(st.find(it-1)==st.end())
      {
            int num=it;
            int cnt=1;
            while(st.find(num+1)!=st.end())
            {
                num+=1;
                cnt++;
            }
            mxlen=max(cnt,mxlen);

      }

        }
        return mxlen;
    }
};
