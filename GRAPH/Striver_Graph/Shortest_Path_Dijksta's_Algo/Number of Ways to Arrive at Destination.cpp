
class Solution {
public:


    typedef pair<long long, long long> pi;
    int countPaths(int n, vector<vector<int>>& roads)
    {

           vector< pair<long long,long long> >adj[n+1];

        for(auto it: roads)
        {
                adj[it[0]].push_back({it[1], it[2]});
                  adj[it[1]].push_back({it[0], it[2]});
        }


        priority_queue< pi , vector< pi > , greater< pi > >pq  ;
    vector<long long >dist(n,1e18);
    vector<long long>ways(n,0);

     dist[0]=0;
     pq.push({0,0});
     ways[0]=1;
    int mod= int(1e9+7);

     while(!pq.empty())
     {
         long long dis=pq.top().first;
         long long node=pq.top().second;

         pq.pop();

         for(auto it : adj[node])
         {
             long long adjN= it.first;
           long long adjW= it.second;

             if(dis+adjW <dist[adjN])
             {
                 dist[adjN]=dis+adjW;

                   pq.push({ dist[adjN] , adjN });
                   ways[adjN]=ways[node];


             }
             else if(dis+adjW ==dist[adjN])
             {
                 ways[adjN]= ( ways[adjN] + ways[node])%mod;

             }

         }
     }

     return ways[n-1]%mod;

    }
};
