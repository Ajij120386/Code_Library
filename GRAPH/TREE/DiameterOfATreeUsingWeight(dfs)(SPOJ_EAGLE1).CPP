#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
vector <pair<int, int> >adj[N];
ll dist[N],dist1[N];
ll mx, mxnode,node1,node2;

void dfs(int node, int par)
{

      for (int i = 0; i < adj[node].size(); i++)
     {

        int child = adj[node][i].first;
         ll dg = adj[node][i].second;

       if (child != par)
     {
         dist[child] = dist[node] + dg;

        if (dist[child] > mx)
        {
             mx = dist[child];
             mxnode = child;
        }
       dfs(child, node);
     }
 }

 }
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t, cs = 0;
     cin >> t;

    while (t--)
   {

      memset(dist, 0, sizeof(dist));
      memset(dist1, 0, sizeof(dist1));
         mx = 0;
       int n;
      cin >> n;
         for (int i = 1; i < n; i++)
     {
          ll u, v, d;
          cin >> u >> v >> d;

         adj[u].push_back({v, d});
         adj[v].push_back({u, d});
     }

          dfs(1, 0);
                 mx = 0;
                node1=mxnode;
           memset(dist, 0, sizeof(dist));



           dfs(node1, 0);

                for (int i = 1; i <= n; i++)
               dist1[i] = dist[i];

            node2=mxnode;
             memset(dist, 0, sizeof(dist));

             dfs(node2, 0);

       for (int i = 1; i <= n; i++)
         cout << max(dist1[i], dist[i]) << " ";


     for (int i = 1; i <= n; i++) adj[i].clear();
   }

 }
