
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

#define mx 10009
const int N = 2e5;
vector<ll>adj[N],val,ans;

ll n,m,ar[N],cnt;
     map<ll,ll>mp;

void bfs(vector<ll> &v)
{



         queue < int >q;

         for(auto it: v){

           q.push(it);
           mp[it] = 0;
         }

         while(!q.empty())
        {

            if(ans.size()==m)
                 break;
             int node = q.front();
             q.pop();

             if(mp[node]){

                    cnt+=mp[node];
                  ans.pb(node);

             }

                if(mp.count(node-1)==0)
                 {
                    q.push(node-1);
                    mp[node-1]=mp[node]+1;

                 }
                 if(mp.count(node+1)==0)
                 {
                    q.push(node+1);
                    mp[node+1]=mp[node]+1;

                 }
            }


        }







void solve()
{

           int a,b,r,c,q,x,y,f,s=0,ok=0,ya=0;
           string st;
           cin>>n>>m;

           val.resize(n);
        for(int i=0;i<n;i++)
   {
          cin>>val[i];



   }




    bfs(val);

    cout<<cnt<<endl;
for(auto it: ans){

               cout<<it<< " ";
        }
        cout<<endl;


   }

int main(){

fastio;

int t,tc=0;
t=1;
//ci(t);

w(t){

   solve();


}
}
