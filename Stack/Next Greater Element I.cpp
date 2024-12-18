
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

   int n=nums.size();
    vector<int>ans(n,-1);

    stack<int>st;

    for(int i=n-1;i>=0;i--)
    {

        while(st.empty()==false && st.top()<=nums[i]) st.pop();

     if(st.empty()==false) ans[i]=st.top();
        st.push(nums[i]);
    }
  return ans;

    }
};
