
class Solution {
public:

typedef pair<int, int> pi;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector< pair<int,int> >adj[n+1];

        for(auto it: times)
        adj[it[0]].push_back({it[1], it[2]});



        priority_queue< pi , vector< pi > , greater< pi > >pq  ;
    vector<int>dist(n+1,1e9);

     dist[k]=0;
     pq.push({0,k});

     while(!pq.empty())
     {
         int dis=pq.top().first;
         int node=pq.top().second;

         pq.pop();

         for(auto it : adj[node])
         {
             int adjN= it.first;
             int adjW= it.second;

             if(dis+adjW <dist[adjN])
             {
                 dist[adjN]=dis+adjW;

                   pq.push({ dist[adjN] , adjN });


             }

         }
     }


        int ans=INT_MIN;

        for(int i=1;i<=n;i++)
        {
            ans=max(dist[i],ans);
        }

        if(ans==1e9) return -1;
        return ans;
    }
};
