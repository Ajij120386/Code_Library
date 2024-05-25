

//USING BFS

class Solution {
public:

void bfs( vector<int> adj[],int i,vector<int>&vis)
{
      queue<int>q;
        q.push(i);
        vis[i]=1;

        while(!q.empty()){

           int node=q.front();
             q.pop();

         //  ans.push_back(node);
           for(auto it: adj[node]){

             if (!vis[it]) {

                q.push(it);
                vis[it] = 1;
             }
           }
        }

}
    int findCircleNum(vector<vector<int>>& isConnected) {

            int n= isConnected.size();
         vector<int> adj[n];

        // to change adjacency matrix to list
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
    // Write your code here.


    vector<int>vis(n,0);


    for(int i=0;i<n;i++){

     if(!vis[i]){

          ans++;
          bfs(adj,i,vis);

     }
    }

    return ans;
    }
};


//UISNG dfs
class Solution {
public:

void dfs( vector<int> adj[],int i,vector<int>&vis)
{

        vis[i]=1;

           for(auto it: adj[i]){

             if (!vis[it]) {
                dfs(adj,it,vis);
             }
           }
        }


    int findCircleNum(vector<vector<int>>& isConnected) {

            int n= isConnected.size();
         vector<int> adj[n];

        // to change adjacency matrix to list
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
    // Write your code here.


    vector<int>vis(n,0);


    for(int i=0;i<n;i++){

     if(!vis[i]){

          ans++;
          dfs(adj,i,vis);

     }
    }

    return ans;
    }
};
