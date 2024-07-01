//Approach-3 (Using Topological Sorting)
//T.C : O(n + m + n^2 + nlogn) -> O(n+m) for building the graph and performing the topological sort,
//                     -> O(n^2) for processing each node and merging ancestor lists.
//                     -> O(nlogn) for sorting the ancestor lists for each node.
//S.C : O(n^2+m)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj; //S.C : O(V+E)

        vector<int> indegree(n, 0);

        for(vector<int>& vec : edges) { //O(E)
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); //u --> v
            indegree[v]++;
        }


        //TOPOLOGICAL SORTING
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topoOrder;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            topoOrder.push_back(curr);

            for(int &v : adj[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<unordered_set<int>> vec(n);

        for(int &node : topoOrder) {
            for(int &v : adj[node]) {
                vec[v].insert(node); //adding node ancestor
                vec[v].insert(vec[node].begin(), vec[node].end()); //adding ancestors of node
            }
        }

        for(int i = 0; i < n; i++) {
            result[i] = vector<int>(vec[i].begin(), vec[i].end());

            sort(result[i].begin(), result[i].end());
        }


        return result;
    }
};
