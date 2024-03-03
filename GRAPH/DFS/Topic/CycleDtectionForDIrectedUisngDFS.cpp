
#include<bits/stdc++.h>
using namespace std;


    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {

        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : adj[node]) {

            if(!vis[it]) {

                if(checkCycle(it, adj, vis, dfsVis))
                    return true;
            }
        else if(dfsVis[it]){

                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }



int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	int vis[V], dfsVis[V];
	   memset(vis, 0, sizeof vis);
	   memset(dfsVis, 0, sizeof dfsVis);

	   	bool ans=false;

	   for(int i = 0;i<V;i++){
	       if(!vis[i]) {

	           if(checkCycle(i, adj, vis, dfsVis)) {
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
10 9
1 2
3 4
4 5
6 5
3 6
2 7
7 8
8 9
9 7
cycle exists



1
10 9
1 2
3 4
4 5
6 5
3 6
2 7
7 8
8 9
7 9
cycle NOT exists

*/
