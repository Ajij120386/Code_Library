#include<bits/stdc++.h>
const int N = 2e5;
set<int>adj[N + 100];
bool vis[N + 100];
int val = 0;
vector<int>ans;

void bfs(int start)
{

        queue < int> q;
         q.push(start);
         vis[start] = 1;

         while(!q.empty())
        {
             int node = q.front();
             q.pop();

            ans.push_back(node);

           for (auto it: adj[node])
            {
                if(!vis[it])
                 {
                   q.push(it);
                   vis[it] = 1;
                 }
            }
        }

    }
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
       for(int i=0;i<edges.size();i++)
   {
           int a= edges[i].first;
             int b= edges[i].second;
        adj[a].insert(b);
        adj[b].insert(a);
   }


     for(int i=0;i<vertex;i++)
   {
       if(!vis[i])
       {
           bfs(i);

        }
   }
    return ans;

}
