class Solution {
public:

  int drow[4]={ -1,0,+1,0};
  int dcol[4]={ 0, 1,0,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int n=maze.size();
        int m=maze[0].size();

        queue< pair< pair<int,int > , int> >q;

         q.push({ { entrance[0],entrance[1]},0});


         while(!q.empty())
         {
            auto it=q.front().first;
            int r=it.first;
            int c=it.second;

            int dis=q.front().second;
            q.pop();

            if( it!= make_pair(entrance[0],entrance[1]) &&  (  r==0 || c==0 || r==n-1 || c==m-1) )
            {

                  return dis;
            }

            for(int i=0;i<4;i++)
            {
                int nr=r+drow[i];
                int nc=c+dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.')
                {
                    q.push( { {nr,nc},dis+1 });
                    maze[nr][nc]='+';

                }
            }
         }
         return -1;
    }
};
