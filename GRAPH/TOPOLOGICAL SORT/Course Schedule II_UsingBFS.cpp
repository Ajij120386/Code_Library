
class Solution {
public:

      vector<int>topoSort(int n, vector<int>adj[] )
   {
        vector<int>indegree(n,0);
         for(int i=0;i<n;i++)
         {
            for(auto it: adj[i])
             indegree[it]++;
         }
         queue<int>q;

         for(int i=0;i<n;i++)
         {
            if(indegree[i]==0) q.push(i);
         }

         vector<int>topo;

    while(!q.empty())
    {

        int node=q.front();
        topo.push_back(node);
        q.pop();

        for(auto it: adj[node])
        {

           indegree[it]--;

           if(indegree[it]==0) q.push(it);

        }
    }

    return topo;
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

         int n=numCourses;
        vector<int>adj[numCourses];


        for(auto it: prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adj[v].push_back(u);

        }
        vector<int>Topo= topoSort(n,adj);

         if(Topo.size()==n)
            return Topo;
         else return {};

    }



};
