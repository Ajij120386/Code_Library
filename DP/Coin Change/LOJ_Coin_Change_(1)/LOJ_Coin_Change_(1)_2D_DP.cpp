
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

//Constants

const ll INF= LONG_LONG_MAX;
const ll MOD=1e8+7;


inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;

 // cout << *p.find_by_order(k) << endl;  Returns the address of the element at kth index (while using zero-based indexing)

 // cout << p.order_of_key(k)<<endl; Returns the number of elements strictly smaller than k.




// Macros
#define F first
#define S second
#define pb push_back

#define vr(v) v.begin(),v.end()
#define fio(i,n) for(int i=1;i<=n;i++)
#define fiz(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n;i>=0;i--)
#define co(n) cout<<n<<endl
#define coy cout<<"YES"<<endl
#define con cout<<"NO"<<endl
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

const int N=55;
ll v[55],mp[101],dp[N][1005];


ll coin(ll ind,ll T)
{

    if(ind<0)
     {
        if(T==0)
             return 1;

         return 0;

    }

    if(dp[ind][T]!=-1)
         return dp[ind][T];



     int cnt=0;

      for(int i=0;i<=mp[v[ind]];i++)
    {
       ll sum=(i*v[ind]); //this ensure that we always take unique set of number
       if(sum<=T)
       {

          cnt+=coin(ind-1,T-sum);
          cnt%=MOD;
        }
    }
    return dp[ind][T]=cnt;

}
void solve(){


         int  a1,a2,b,T,l,r,c,n,m,p,x,y=0,z,s=0,Ts=0,cnt=0,mx=0,ok=0,ya=0;;
     cin>>n>>T;

     memset(dp,-1,sizeof(dp));

     // vector<ll>id(n+1,0);



       for(int i=0;i<n;i++)
       {
           cin>>v[i];

       }

       for(int i=0;i<n;i++)
       {
           cin>>x;
           mp[v[i]]=x;

       }



    cout<<coin(n-1,T)<<endl;



}
int main(){

fastio;

int t=1,tc=0;
cin>>t;

for(int i=1;i<=t;i++){

            cout<<"Case "<<i<<": ";
                solve();


}
}
/*****************  ALHAMDULILLAH  *****************/


