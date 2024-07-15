
class Solution {
public:

typedef pair<int,int>p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector< pair<int ,int> > adj[n];

         queue< pair<int, p > > q;

         vector<int>dist(n,1e9);

      for(auto it : flights)
      {
         adj[it[0]].push_back({it[1],it[2]});
      }

       q.push({0,{src,0}});

       while(!q.empty())
       {
          auto it= q.front();
          q.pop();
          int stops=it.first;
          int node= it.second.first;
          int cost= it.second.second;


          if(stops>k) continue;
          for(auto it: adj[node])
          {
            int adjNode=it.first;
            int adjCost= it.second;

             if( cost+adjCost < dist[adjNode]  && stops<=k)
             {
                 dist[adjNode] =cost+adjCost;
                 q.push({stops+1, { adjNode, cost+adjCost} } );
             }

          }


       }

if(dist[dst]==1e9) return -1;
return dist[dst];


    }
};
