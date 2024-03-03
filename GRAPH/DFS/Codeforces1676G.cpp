#include<bits/stdc++.h>
using namespace std;
const int mx=1e4;
vector< vector<int> >adj;
int ans=0;
int valstore[mx];
int k;
int dfs(int node)
{
	int val =valstore[node];
	if(adj[node].empty())
        return val;
	for(auto it : adj[node])
	{

		val+=dfs(it);
	}
	if(val==0) ans++;
	return val;
}
int main( )
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ans=0,k=0;
		adj.clear();
		adj.resize(n+1);
		for(int i=2;i<=n;i++)
		{
			int m;
			cin>>m;
			adj[m].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			char a;
			cin>>a;
			if(a=='W')
			valstore[i]=1;
			else
			valstore[i]=-1;
		}
		dfs(1);
	    cout<<ans<<endl;
	}

	return 0;
}

