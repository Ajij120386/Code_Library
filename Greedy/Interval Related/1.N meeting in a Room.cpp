


/////*********** Striver PRoblem  Position Print***********

  struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
   public:
      bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
   void maxMeetings(int s[], int e[], int n) {
      struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator);

      vector < int > answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].pos);

      for (int i = 1; i < n; i++) {

             // [1,2] and [2,3] are overlapping
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) {
         cout << answer[i] << " ";
      }

   }

};


/////*********** GFG n meeting in  a room***********


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

      struct meeting
      {
          int start,end,pos;
      };
      static bool cmp(struct meeting m1, meeting m2)
      {
          return (m1.end< m2.end) ;
      }

    int maxMeetings(vector<int>& start, vector<int>& end) {

        int n=start.size();

         struct meeting meet[n];

        for(int i=0;i<n;i++)
        {
             meet[i].start=start[i];
              meet[i].end=end[i];
        }

        sort(meet,meet+n,cmp);

        int limit= meet[0].end;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
                  // [1,2] and [2,3] are overlapping
            if(meet[i].start > limit)
            {
                cnt++;
                limit= meet[i].end;
            }

        }
        return cnt;

        // Your code here
    }
};

