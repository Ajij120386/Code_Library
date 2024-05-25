


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {


        int n=mat.size();
        int m=mat[0].size();


       int vis[n][m];

       vector<vector<int>>dis(n,vector<int>(m,0));

    queue< pair< pair<int,int> , int > > q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0){

                     q.push({ {i,j},0});
                     vis[i][j]=0;

                }
                else{
                      vis[i][j]=1;
                }

            }
        }

       int dx[8]={-1,1,0,0,-1,-1,1,1};
       int dy[8]={0,0,-1,1,-1,1,-1,1};

      while(!q.empty())
      {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        dis[r][c]=t;

        q.pop();

        for(int i=0;i<4;i++)
        {

                 int  nr= r+dx[i];
                 int  nc= c+dy[i];

          if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==1  )

               {
                  q.push({ {nr,nc},t+1 });
                  vis[nr][nc]=0;



               }

        }

      }
return dis;

    }


};
