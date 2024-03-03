const int N = 2e5;

vector<int>adj[N + 100];



bool vis[N + 100];
int val = 0;
vector<int>res;

void dfs(int node)
{
    vis[node] = true;

    val++;
    res.push_back(node);
    for(auto it: adj[node])
    {
        if(vis[it] == false)
        {
            dfs(it);
        }
    }
}
void clearing(int n)
{
    for(int i=0; i<=n+5; i++)
    {
        vis[i] = false;
        adj[i].clear();
    }
}
vector<int> countNodes(int n, int m, vector< vector<int> > & edges)
{

    clearing(n);

     for(int i=0;i<m;i++)
     {
         int a=edges[i][0];
          int b=edges[i][1];

         adj[a].push_back(b);
          adj[b].push_back(a);
     }


    vector<int>cnt(n,0);
     for(int i=0; i<n; i++)
        {
            if(vis[i] == false)
            {
                val = 0;
                dfs(i);

                for(auto it: res)
                {

                    cnt[it] = val;
                }

                res.clear();


            }

        }
    return cnt;

}
