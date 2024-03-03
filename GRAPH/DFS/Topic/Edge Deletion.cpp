
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int mod = 1e9+7;
vector<int> adj[N];

int subtree_sum[N];
int val[N];

void dfs(int vertex,int parent)
{


     subtree_sum[vertex]+=val[vertex-1];

	for(int child : adj[vertex])
	{
		if(child==parent)
             continue;


		dfs(child,vertex);

      subtree_sum[vertex]+=subtree_sum[child];


	}


}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
	{
        cin>>val[i];

	}
	for(int i=0;i<n-1;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
       adj[v1].push_back(v2);
	   adj[v2].push_back(v1);

	}

     dfs(1,0);
     long long ans=0;
    for(int i=2;i<=n;i++)
    {
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part1;
        ans=max(ans,(part1*part2*1ll)%mod);

    }
cout<<ans<<"\n";
	return 0;
}

/*
4
10 5 12 6
1 2
1 4
4 3
*/
