
//Approach-------1

class Solution {
public:



    int orangesRotting(vector<vector<int>>& grid) {


        int n=grid.size();
        int m=grid[0].size();

       int cntFresh=0,tmax=-1,cnt=0;
       int vis[n][m];

    queue< pair<int,int> > q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){

                     q.push( {i,j});
                     vis[i][j]=2;
                }
                else{
                      vis[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
       if(cntFresh==0) return 0;
       int dx[8]={-1,1,0,0,-1,-1,1,1};
       int dy[8]={0,0,-1,1,-1,1,-1,1};

      while(!q.empty())
      {

        int sz=q.size();


            tmax++;
         while(sz--)
         {
                int r=q.front().first;
             int c=q.front().second;

             q.pop();

             for(int i=0;i<4;i++)
        {

                 int  nr= r+dx[i];
                 int  nc= c+dy[i];

          if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1 )

               {
                  q.push( {nr,nc});
                  vis[nr][nc]=2;
                  cnt++;

               }

        }

         }


      }

     if(cnt<cntFresh) return -1 ;

     return tmax;

    }
};

//Approach---2
class Solution {
public:



    int orangesRotting(vector<vector<int>>& grid) {


        int n=grid.size();
        int m=grid[0].size();

       int cntFresh=0,tmax=0,cnt=0;
       int vis[n][m];

    queue< pair< pair<int,int> , int > > q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){

                     q.push({ {i,j},0});
                     vis[i][j]=2;
                }
                else{
                      vis[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }

       int dx[8]={-1,1,0,0,-1,-1,1,1};
       int dy[8]={0,0,-1,1,-1,1,-1,1};

      while(!q.empty())
      {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tmax=max(t,tmax);
        q.pop();

        for(int i=0;i<4;i++)
        {

                 int  nr= r+dx[i];
                 int  nc= c+dy[i];

          if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1 )

               {
                  q.push({ {nr,nc},t+1 });
                  vis[nr][nc]=2;
                  cnt++;

               }

        }

      }

     if(cnt<cntFresh) return -1 ;

     return tmax;

    }
};
