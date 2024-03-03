
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
#define mx 105
vector<int>adj[mx];
int vis[mx],out[mx],in[mx];
int xx=1;


void dfs(int node){

  vis[node]=1;
  in[node]=xx++;

  for(auto it: adj[node]){

    if(!vis[it])
        dfs(it);
  }
  out[node]=xx++;
}

int main(){

fastio;

int n,m,a,b,u,v;
cin>>n;

for(int i=0;i<n;i++)
{

    cin>>u>>m;
     while(m--)
     {

         cin>>v;
        adj[u].push_back(v);
//adj[b].push_back(a);
    }
}


   for(int i=1;i<=n;i++){
       if(!vis[i]){

          dfs(i);
       }

   }

   for(int i=1;i<=n;i++){
        cout<<i<<" "<<in[i]<<" "<<out[i]<<endl;

}
}

/*****************  ALHAMDULILLAH  *****************/

/*

input:
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0

output:

1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6

*/
