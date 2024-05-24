

/*
  Brute Force Approach
Time Complexity: O(N*logN) + O(2*N)

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

    vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            int st=intervals[i][0];
            int ed=intervals[i][1];

            if(!ans.empty() && ans.back()[1]>=ed)  //ans={1,6}  ,,, (2,4)
            continue;


            for(int j=i+1;j<n;j++)
            {
                 if(intervals[j][0]<=ed)
                 {
                    ed=max(intervals[j][1],ed);
                 }
                 else
                 break;

            }
          ans.push_back({st,ed});
        }
        return ans;
    }
};


/*
  Optimal  Approach
Time Complexity: O(N*logN) + O(N),


*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


         int n=intervals.size();
        sort(intervals.begin(),intervals.end());

    vector<vector<int>> ans;

       for(int i=0;i<n;i++)
        {

            if(ans.empty() || intervals[i][0]>ans.back()[1])

              ans.push_back( intervals[i]);

              else
              {
                    ans.back()[1]=max(ans.back()[1],intervals[i][1]);
              }




        }
         return ans;
    }
};
