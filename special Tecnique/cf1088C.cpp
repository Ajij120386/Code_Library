 #include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair

ll arr[100005];
vector <ll> adj[1000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	ll n,i,j,sm=0,k=1000000,a;
	cin >> n;

	for(i=0;i<n;i++)
		cin >> arr[i];

	cout << n+1 << endl;
	cout << 2 << " " << n << " " << 1 << endl;
	cout << 1 << " " << n << " " << k << endl;

	for(i=1;i<n;i++)
		cout << 2 << " " << i << " " << k-- << endl;
	return 0;
}
