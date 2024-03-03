/******* BISMILLAHIR RAHMANIR RAHIM *******/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//TypeDEfN
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;



typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;

//Constants

const ll INF= LONG_LONG_MAX;
const ll mod=1e9+7;

// Macros
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define fio(i,n) for(int i=1;i<=n;i++)
#define fiz(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n;i>=0;i--)
#define co(n) cout<<n<<endl
#define coy cout<<"Yes"<<endl
#define con cout<<"No"<<endl
#define ci(n) cin>>n
#define w(x) while(x--)
#define ci2(a,b) cin>>a>>b
#define ci3(a,b,c) cin>>a>>b>>c

#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rvs(v) reverse(v.begin(),v.end());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

#define MX 100
int parent[MX];
int Rank[MX];
void makeSet(int n){
    for (int i = 0; i < n; i++){
    parent[i] = i;
    Rank[i]=0;
   }
}


int FindPar(int u){

    if (u == parent[u])
           return u;

    return parent[u] = FindPar(parent[u]);
}

void Union(int u, int v)
{

    u = FindPar(u);
    v = FindPar(v);

       if(Rank[u] < Rank[v])
        {
    	parent[u] = v;
       }
    else if(Rank[v] < Rank[u])
        {
    	parent[v] = u;
         }
    else
    {
    	parent[v] = u;
    	Rank[u]++;
    }
}

void solve()
{

           int a,b,r,c,q,x,y,f, m,s=0,n,cnt=0,ok=0,ya=0;
           string st;
           cin>>n>>m;
vector<pair<int, pair<int,int> > >edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({ wt, {u,v}});

    }
    sort(edges.begin(),edges.end());

    makeSet(n);

    int total_cost=0;

    vector<pair<int,int>> mst;

    for(auto it: edges)
  {

        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;

        if(FindPar(u)!=FindPar(v))
        {

            Union(u,v);
            total_cost+=wt;
             mst.push_back({u, v});
        }

  }

    cout << total_cost << endl;
	for(auto it : mst) {

       cout << it.first << " - " << it.second << endl;
	}


   }
int main(){

fastio;

int t,tc=0;
ci(t);

w(t){

   solve();


}
}
