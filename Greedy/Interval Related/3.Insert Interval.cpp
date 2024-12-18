
class Solution {
public:


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


            vector<vector<int>>res;

        int n= intervals.size(),i=0;


    //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval


        while(i<n && intervals[i][1]< newInterval[0])
        {
             res.push_back( intervals[i]);
             i++;
        }



    //case 2: overlapping case and merging of intervals

          while(i<n && intervals[i][0] <=newInterval[1])
        {

             newInterval[0]= min(intervals[i][0], newInterval[0] );
             newInterval[1]= max(intervals[i][1], newInterval[1] );
             i++;
        }

        res.push_back( newInterval);



    // case 3: no overlapping of intervals after newinterval being merged

         while(i<n )
        {
             res.push_back( intervals[i]);
             i++;
        }

return res;
    }
};
