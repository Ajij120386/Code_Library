
class Solution {
public:

    int target;
     void dfs(vector<vector<int>>& adj, int node, vector<int>& temp, vector<vector<int>>& result ) {

          temp.push_back( node);

        if(node == target) {
            result.push_back(temp);
            return;

        }

        for(int &it : adj[ node]) {

            dfs(adj, it, temp, result);
                temp.pop_back();

        }

    }



    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {


         vector<vector<int>> result;
        vector<int> temp;
        target = graph.size()-1;

        dfs(graph, 0, temp, result);

        return result;
        return result;



    }
};
