#include<bits/stdc++.h>
using namespace std;


    bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(checkForCycle(it, node, vis, adj))
                    return true;
            }
            else if(it!=parent)
                return true;
        }

        return false;
    }



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool ans=false;
		vector<int> vis(V+1, 0);

	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, -1, vis, adj)) {
                        ans=true;
                break;
	        }
	    }

	    }
		if(ans)
			cout << "Cycle Exists"<<endl;

		else
            cout << "Cycle NOT Exists"<<endl;


}

}
/*

1
9 7
1 3
3 4
2 5
5 6
6 7
7 8
8 5
cycle exists

*/
