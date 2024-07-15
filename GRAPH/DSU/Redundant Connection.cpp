class Solution {
public:

  class DSU{

     public:
        vector<int>par;
        vector<int>rank;

        DSU(int n)
        {
            par.resize(n+1);
            rank.resize(n+1);
            for(int i=0;i<n;i++) par[i]=i;

        }

       int  findPar(int node)
        {
             if(node==par[node]) return node;

            return par[node]=findPar(par[node]);
        }
        void Union(int u, int v)
        {
            u=findPar(u);
            v=findPar(v);

            if(rank[u]<rank[v])

                par[u]=v;
            else  if(rank[u]>rank[v])

                par[v]=u;

            else{
                 par[v]=u;
                 rank[u]++;
            }
        }


  };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<int>ans;

      int n=edges.size();
      DSU ds(n);

      for(auto it: edges)
      {
        int u= it[0];
        int v= it[1];

        if( ds.findPar(u)!=ds.findPar(v))
          ds.Union(u,v);
        else
            return it;

      }
        return { };
    }
};
