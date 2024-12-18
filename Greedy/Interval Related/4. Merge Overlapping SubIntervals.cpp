
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        int n=intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<n;i++)
        {

                  // if the current interval does not lie in the last interval:

            if(res.empty() || intervals[i][0]> res.back()[1])
               res.push_back(intervals[i]);


             // if the current intervals lies in the last interval:
           else
               res.back()[1]=max(intervals[i][1],res.back()[1]);

        }


    return res;

    }
};
