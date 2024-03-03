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

#define mx 10009
const int N = 2e5;
vector<int>adj[N],odd,even;

int n,ans[N],ar[N];

void bfs(vector<int> &v)
{
         int len[n];
        memset(len,-1,sizeof(len));
         queue < int >q;

         for(auto it: v){

           q.push(it);
           len[it] = 0;
         }

         while(!q.empty())
        {
             int node = q.front();
             q.pop();



           for (auto it: adj[node])
            {
                if(len[it]==-1)
                 {
                    q.push(it);
                   len[it] = len[node]+1;
                 }
            }
        }

        for(int i=0;i<n;i++){

            if(len[i]>0)
                ans[i]=len[i];
        }

    }



void solve()
{

           int a,b,r,c,q,x,y,f, m,s=0,cnt=0,ok=0,ya=0;
           string st;
           cin>>n;


        for(int i=0;i<n;i++)
   {
          cin>>ar[i];
          if(ar[i]%2)

                 odd.push_back(i);
         else
               even.push_back(i);
   }

    for(int i=0;i<n;i++){

 if(i+ar[i]<n) adj[i+ar[i]].pb(i);
 if(i-ar[i]>=0) adj[i-ar[i]].pb(i);

    }


    bfs(odd);
    bfs(even);

     for(int i=0;i<n;i++)
   {
       if(ans[i])
       {
          cout<<ans[i]<<" ";

        }
        else
            cout<<-1<<" ";

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
