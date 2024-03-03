#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];

int subtree_sum[N];
int even_cnt[N];

void dfs(int vertex,int parent)
{

	if(vertex%2==0) even_cnt[vertex]++;
     subtree_sum[vertex]+=vertex;

	for(int child : adj[vertex])
	{
		if(child==parent)
             continue;


		dfs(child,vertex);

      subtree_sum[vertex]+=subtree_sum[child];
      even_cnt[vertex]+=even_cnt[child];

	}


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

     dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<subtree_sum[i]<<" "<<even_cnt[i]<<"\n";
    }

	return 0;
}

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

*/
