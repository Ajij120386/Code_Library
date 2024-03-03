
/******* BISMILLAHIR RAHMANIR RAHIM *******/

#include<bits/stdc++.h>
using namespace std;


//TypeDEf
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

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
#define mx 100001
vector<int>adj[mx];
int vis[mx];
void dfs(int node,vector<int>&v){

  vis[node]=1;
  v.push_back(node);
  for(auto it: adj[node]){

    if(!vis[it])
        dfs(it,v);
  }
return;
}
int main(){

fastio;

int n,m,a,b;
ci2(n,m);

fio(i,m){

cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}

   fio(i,n){
       if(!vis[i]){
            vector<int>vec;
        dfs(i,vec);
       }

   }


}


/*****************  ALHAMDULILLAH  *****************/
