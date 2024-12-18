
class Solution {
public:


    typedef long long LL;


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

    int maximumDetonation(vector<vector<int>>& bombs) {

        int n=bombs.size(),ans=INT_MIN;
        vector<int>adj[n];

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {

                if(i == j) //same bomb
                    continue;

                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];

                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];

                //Make a directed edge from i to j if i can detonate j as well

                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }

            }
        }



        for(int i=0;i<n;i++)
        {

                int size=0;

               vector<int>vis(n,0);

                 DFS(i,bombs,vis,size,adj);

                 ans=max(ans,size);

            }

        return ans;



    }
};
