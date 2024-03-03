
#include <bits/stdc++.h>
using namespace std;


    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {
                findTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }




// Function to assign directions
void assignDirections(vector<int> adj[], vector<pair<int, int>> &undir, vector<int> &topo){

    unordered_map<int, int> indexes;
    int j = 0 ;

    for(auto it: topo){

        indexes[it] = j ;
        j++;
    }

    for(auto it : undir ){
        int firstNode = it.first;
        int secondNode = it.second;

        if(indexes[firstNode] < indexes[secondNode]){

            adj[firstNode].push_back(secondNode);
        }
        else{
            adj[secondNode].push_back(firstNode);
        }
    }

}
int main() {

        int N, E,U;
        cin >> N >> E>>U;
        int u, v;

        vector<int> adj[N+1];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }


              vector<pair<int, int>> undir(U+1);




        for (int i = 0; i < U; i++) {

            cin >> undir[U].first >>undir[U].second;

        }



         stack<int> st;
	    vector<int> vis(N+1, 0);

	    for(int i = 0;i<N;i++) {

	        if(vis[i] == 0) {
	            findTopoSort(i, vis, st, adj);
	        }
	    }

	    vector<int> topo;

	    while(!st.empty()) {
	        topo.push_back(st.top());
	        st.pop();
	    }



    for(auto it: topo) cout<<it<<" ";
            cout<<endl;




     // assign directions to undirected edges
    assignDirections(adj, undir, topo);

    // print graph



    for(int i=0;i<N;i++){

        cout<<i<<" : ";

        for(int j=0;j<adj[i].size();j++){

        cout<<adj[i][j]<<" ";


    }
    cout<<endl;
    }

}

/*
5 5 3
0 1
1 4
2 0
2 3
3 4
1 2
 0 3
 2 4

output
 2 3 0 1 4
0 : 1 0 0 0
1 : 4
2 : 0 3
3 : 4
4 :
*/

