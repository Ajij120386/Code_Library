
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

int vis[8][8];
int level[8][8];


//knight moves
int dx[]={-1,1,-1,1,2,2,-2,-2};
int dy[]={2,2,-2,-2,-1,1,-1,1};

int getX(string s){

     return s[0]-'a';
}
int getY(string s){

     return s[1]-'1';
}

bool valid(int x,int y){

return(x>=0 && y>=0 && x<8 && y<8 && !vis[x][y]);

}

void reset()
{

  for(int i=0;i<8;i++)
  {
   for(int j=0;j<8;j++)
   {
    level[i][j]=INF;
    vis[i][j]=0;
    }
  }
}

int  bfs(string  src,string dest)
{

    int srcX=getX(src);
    int srcY=getY(src);
    int destX=getX(dest);
    int destY=getY(dest);


      queue<pair<int,int> >q;
       q.push({srcX,srcY});
      vis[srcX][srcY]=1;
      level[srcX][srcY]=0;

     while(!q.empty())
  {
      int x=q.front().first;
      int y=q.front().second;
      q.pop();

      for(int i=0;i<8;i++)
     {
       int nxt_x=x+dx[i];
       int nxt_y=y+dy[i];

       if(valid(nxt_x,nxt_y))
        {
            q.push({nxt_x,nxt_y});
            vis[nxt_x][nxt_y]=1;
            level[nxt_x][nxt_y]=level[x][y]+1;

         }
      }

      if(level[destX][destY]!=INF)
      break;
   }
return level[destX][destY];
}

int main()
{
    int n;
    cin>>n;
	for(int i=0;i<n;i++)
	{
	    reset();
		string s1,s2;
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;;

	}



	return 0;
}

