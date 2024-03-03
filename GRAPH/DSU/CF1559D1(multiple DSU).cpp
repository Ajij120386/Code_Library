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



int FindPar(int *parent,int u){

    if (u == parent[u])
           return u;

  //path compression

    return parent[u] = FindPar(parent,parent[u]);
}

void Union(int *parent,int u, int v)
{

    u = FindPar(parent,u);
    v = FindPar(parent,v);


    if(u!=v)
    {
         parent[v]=u;

    }
}

void solve()
{

           int a,b,r,c,q,m1,m2,x,y,f, m,s=0,n,cnt=0,ok=0,ya=0;
           string st;
           cin>>n>>m1>>m2;

           int p1[n+1],p2[n+1];

      //makeSet
      for(int i=1;i<=n;i++)
      {
          p1[i]=p2[i]=i;
      }

         //To form Diana's Forest
    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin>>u>>v;
      Union(p1,u,v);

    }
      //To form Mocha's Forest
    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin>>u>>v;
      Union(p2,u,v);

    }

   int ans=0;

    vector<pair<int,int>> v;//To store all pairs of nodes legal
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if( ( FindPar(p1,i)!=FindPar(p1,j) ) && ( FindPar(p2,i)!=FindPar(p2,j)  ) )
            {
                  ans++;
                Union(p1,i,j);
                Union(p2,i,j);
                v.pb({i,j});
            }
        }
    }

    cout<<ans<<endl;

    for(auto i:v)
        cout<<i.first<<" "<<i.second<<endl;

   }
int main(){

fastio;

int t=1,tc=0;
//ci(t);

w(t){

   solve();


}
}

