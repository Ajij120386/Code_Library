#include<bits/stdc++.h>
using namespace std;

 vector<int> dijkstra(int n,vector<pair<int,int> > adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(n, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it.first;
                int w = it.second;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;

                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
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
