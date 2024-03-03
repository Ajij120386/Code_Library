

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

const int N=1e5+7;
int parent[N];
int Size[N];
int Rank[N];

void makeSet(int n){
    for (int i = 1; i <=n; i++){
    parent[i] = i;
     Size[i]=1;
     Rank[i]=0;
   }
}


int FindPar(int u){

    if (u == parent[u])
           return u;
//path compression
    return parent[u] = FindPar(parent[u]);
}

bool Union(int u, int v)
{

    u = FindPar(u);
    v = FindPar(v);

    /*
    //union By Rank

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
    */
//union by size
if(u==v) return false;
    if(u!=v){

        if(Size[u]<Size[v])  swap(u,v);
         parent[v]=u;
         Size[u]+=Size[v];
         return true;
    }
}

void solve() {

    int n, v;
    cin >> n;
    makeSet(n);

    int a[n], ans = n, mx = -1, mn = N + 10;
    set<int> ok;

    // connect v with value just greater than v
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v = a[i];
        if (v > mx) {
            mx= v;
            ok.insert(v);
            continue;
        }

        auto it = ok.lower_bound(v);
        if (Union(v, *it)) ans--;
        ok.insert(v);

    }

    // connect the smallest value a[n-i..n] with greater one in a[0..i]
    for (int i = n - 1; i >= 0; i--) {
        if (mn> a[i]) {
            mn = a[i];
            continue;
        }

        if (Union(a[i], mn)) ans--;

    }

    cout << ans << endl;

}


int main() {

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
