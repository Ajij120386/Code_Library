
///sliding-window-maximum     solved using DEQUE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

         int n=nums.size();
         vector<int>ans;
         deque<int>q;
        long long i=0,j=0,sum=0,res=INT_MIN;
        while(j<n)
        {
            while(!q.empty() && q.back()<nums[j])

               q.pop_back();

             q.push_back(nums[j]);


             if(j-i+1<k)
                     j++;
              else{

                  ans.push_back(q.front());
                  if(q.front()==nums[i])
                     q.pop_front();
                  i++;
                  j++;
              }


        }
        return ans;


    }
};
