
class Solution {
public:

    void DFS(int node,vector<vector<int>>& edges,vector<int>& vis,int & size, vector<int>adj[])
    {
        vis[node]=1;
         size++;
        for(auto it: adj[node])
        {
            if(vis[it]==0)
               DFS(it,edges,vis,size,adj);
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {


      long long rem=0,s=0;



        vector<int> adj[n];

         for(auto it : edges) {

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

       vector<int>vis(n,0);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int size=0;
                 DFS(i,edges,vis,size,adj);

                s+= size*(n-size-rem);

                rem+=size;

            }
        }
        return s;

    }
};
