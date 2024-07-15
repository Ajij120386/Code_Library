class Solution {
public:

   bool checkCycle(int node,vector<int>&vis, vector<int>&dfsvis, vector<int>adj[])
   {

        vis[node]=1;
        dfsvis[node]=1;

        for(auto it: adj[node])
        {
            if(!vis[it]){

                    if(checkCycle(it,vis,dfsvis,adj) )
                      return true;
            }
            else if(dfsvis[it])  //pai gesi re  mama
                return true;

        }
       dfsvis[node]=0;
       return false;
   }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>adj[numCourses];

        for(auto it: prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adj[v].push_back(u);
        }

           vector<int>vis(numCourses,0);
           vector<int>dfsvis(numCourses,0);


        for(int i=0;i<numCourses; i++)
        {
            if(!vis[i]){

                  if(checkCycle(i,vis,dfsvis,adj) )
                    return false;  //cycle paisi that's means toposort not apply
            }

        }
        return  true;

    }
};
