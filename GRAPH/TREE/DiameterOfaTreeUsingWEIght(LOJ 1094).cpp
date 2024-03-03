
#include<bits/stdc++.h>

using namespace std;
int TC=0;
bool vis[30000];
int dist[30000];
vector < int > adj[30000];
vector < int > weight[30000];

void clr(int n)
{
    for( int i = 0 ; i < n ; i++ )
    {
        vis[i] = 0;
        dist[i] = 0;
    }
}



    void bfs(int src, int n)
{



    queue<int>q;
    vis[src]=1;
    q.push(src);

      while (!q.empty())
   {

        int node = q.front();
        q.pop();

       for(int i=0; i<adj[node].size(); i++)
        {
            int var = adj[node][i];

            if(!vis[var])
            {
                vis[var] = 1;
                dist[var] = dist[node] + weight[node][i]; // distan[ node ] is the node's distance from source.
                q.push(var);
            }
        }
   }
}



int main() {


int t;
cin>>t;
while(t--)
{


TC++;
  int n ;
  cin>>n;

   for( int i = 0 ; i < n ; i++)
  {

            adj[i].clear();
            weight[i].clear();
   }


  int m=n-1;
  int u,v,wt;

  for(int i=0;i<n-1;i++)
  {

       cin>>u>>v>>wt;
       adj[u].push_back(v);
       adj[v].push_back(u);

       weight[u].push_back(wt);
       weight[v].push_back(wt);


  }

  int max_distance=-1,first_node;

  clr(n);

  bfs(0,n);



    // finding the node that's farthest from the node.
        for(int i = 0; i < n; i++)
        {
            if(dist[i]>max_distance)
            {
                max_distance = dist[i];
                first_node=i;
            }
        }

        clr(n);

        int ans=0;

        bfs(first_node,n); // finding the distance of each node from "first_node"

        for(int i=0; i<n; i++)
        {
            if(dist[i]>ans)
            {
                ans = dist[i];
            }
        }
    cout<<"Case "<<TC<<": "<<ans<<endl;
}
}
