const int N = 2e5;

vector<int>adj[N + 100];



bool vis[N + 100];


void dfs(int node)
{
    vis[node] = true;


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
bool checkPathExists(int v, int e, int source, int destination, vector<vector<int>> &edges)
{

    clearing(v);

     for(int i=0;i<e;i++)
     {
         int a=edges[i][0];
          int b=edges[i][1];

         adj[a].push_back(b);

     }



                dfs(source);
                return vis[destination];





}

