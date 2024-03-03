#include<bits/stdc++.h>
using namespace std;


vector<int>ans1;

    bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
         ans1.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {

                if(checkForCycle(it, node, vis, adj))
                    return true;
            }
            else if(it!=parent)
           {
                        ans1.push_back(it);
               return true;
           }
        }
    ans1.pop_back();
        return false;
    }



// { Driver Code Starts.
int main(){
	int tc=1;
	//cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V+1];
		for(int i = 1; i <=E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool ans=false;
		vector<int> vis(V+1, 0);

	    for(int i = 1;i<=V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, -1, vis, adj)) {
                        ans=true;
                break;
	        }
	    }

	    }
		if(ans){
			//cout << "Cycle Exists"<<endl;
			int temp=0;
			int n=ans1.size();
			for(int i=0;i<ans1.size()-1;i++){
                if(ans1[i]==ans1[n-1]){

                 temp=i;
                  break;
                }
			}


			cout<<n-temp<<endl;
			for(int i=temp;i<ans1.size();i++){
                cout<<ans1[i]<<" ";
			}
                cout<<endl;



		}

		else
            cout << "IMPOSSIBLE"<<endl;


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

