

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
const long long INF = 1e9+10;

int vis[N][N];
long long level[N][N];

char grid[N][N];
int n,m,sr,sc,cnt,er,ec,ok;;



int dr[] ={-1,1,0,0,-1,-1,1,1};
int dc[] ={0,0,-1,1,-1,1,-1,1};

string moves="UDLR";
string ans[N][N];




void reset()
{

  for(int i=0;i<n;i++)
  {
   for(int j=0;j<m;j++)
   {
    level[i][j]=INF;
    vis[i][j]=0;
    }
  }
}

void bfs(int sr,int sc)
{

    queue<pair<int,int> >q;
       q.push({sr,sc});
      vis[sr][sc]=1;
      level[sr][sc]=0;
      ans[sr][sc]="";

     while(!q.empty())
  {
      int r=q.front().first;
      int c=q.front().second;
      q.pop();

      for(int i=0;i<4;i++)
     {
      int nr=r+dr[i];
         int nc=c+dc[i];

              if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='#' && !vis[nr][nc])
        {

           ans[nr][nc]=ans[r][c]+moves[i];
            q.push({nr,nc});
            vis[nr][nc]=1;
            level[nr][nc]=level[r][c]+1;

         }
      }

   }

}

int main()
{

       cin>>n>>m;

       reset();

           for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){

                  cin>>grid[i][j];

                  if(grid[i][j]=='A')
                    sr=i, sc=j;
                  if(grid[i][j]=='B')
                    ec=j, er=i;

                }
           }



bfs(sr,sc);



/*
for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){

                     cout<<level[i][j]<<" ";
                }
                cout<<endl;
}


for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){

                     cout<<ans[i][j]<<" ";
                }
                cout<<endl;
}
*/
if(level[er][ec]==INF) cout<<"NO"<<endl;
else{
        cout<<"YES"<<endl;
		   cout<<level[er][ec]<<endl;
			cout<<ans[er][ec]<<endl;

	}


}



