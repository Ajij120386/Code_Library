

int dr[] ={-1,1,0,0,-1,-1,1,1};
int dc[] ={0,0,-1,1,-1,1,-1,1};
class Solution {

    private:

    void bfs(int r,int c,int n,int m,vector<vector<int>>& image,vector<vector<int>>& ans,int color,int inicolor )
    {


      queue<pair<int,int> >q;
      q.push({r,c});

       ans[r][c]=color;


       while(!q.empty()){

           r=q.front().first;
           c= q.front().second;

           q.pop();

           for(int i=0;i<4;i++){

               int nr=r+dr[i];
               int nc=c+dc[i];

               if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==inicolor && ans[nr][nc]!=color )
                 {


                    q.push({nr,nc});
                      ans[nr][nc]=color;
                 }

           }
       }
       }





public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

         int n=image.size();
        int m=image[0].size();

        vector< vector<int> >vis(n,vector<int>(m,0));

        int inicolor=image[sr][sc];
        vector<vector<int> >ans=image;

         bfs(sr,sc,n,m,image,ans,color,inicolor);

         return ans;
    }
};
