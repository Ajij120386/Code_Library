#include<bits/stdc++.h>
using namespace std;

 vector<int> dijkstra(int n,vector<pair<int,int> > adj[], int S)
    {

        // Create a set ds for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        // set stores the nodes in ascending order of the distances
        set<pair<int,int>> st;


        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(n, 1e9);

       st.insert({0, S});

        // Source initialised with dist=0
        dist[S] = 0;

        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
      while(!st.empty()) {

            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edgW = it.second;

                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at
                    // a greater cost.
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                 }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist;
    }




int main(){

	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > adj[n]; 	// 0-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back({b,wt});
		adj[b].push_back({a,wt});
	}

	cin >> source;


	 vector<int> res = dijkstra(n, adj, source);

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
3 3
0 1 1
0 2 6
1 2 3
2

output:
 4 3 0

*/
