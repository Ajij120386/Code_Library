

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
vector<int> adj[N];
int par[N];

//parent store;
void dfs(int vertex,int parent)
{
       par[vertex]=parent;

	for(int child : adj[vertex])
	{

		if(child==parent)
             continue;
        dfs(child,vertex);
	}
}

vector<int>path(int v){

    vector<int>ans;

  while(v!=-1){

    ans.push_back(v);
      v=par[v];

     }
    reverse(ans.begin(),ans.end());

   return ans;
}
int main()
{
    int n;
    cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
       adj[v1].push_back(v2);
	   adj[v2].push_back(v1);

	}

     dfs(1,-1);
     int x,y;
     cin>>x>>y;
     vector<int>path_x=path(x);
     vector<int>path_y=path(y);

     int mn_ln=min(path_x.size(),path_y.size());
     int lca=-1;

    for(int i=0;i<mn_ln;i++)
    {
        if(path_x[i]==path_y[i])
            lca=path_x[i];
        else
            break;
    }
cout<<lca<<endl;
	return 0;
}
/*
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
7 12
*/
