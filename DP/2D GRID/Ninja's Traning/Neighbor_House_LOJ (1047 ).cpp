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
const ll MOD=1e9+7;


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
#define mp make_pair
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

int f(int ind,int prev,int col[][3],vector< vector<int> >&dp)
{


  if(ind==0){

     int mncost=INT_MAX;

     for(int i=0;i<3;i++){
        if(i!=prev)
             mncost=min(mncost,col[0][i]);
     }

    return mncost;
  }

    if(dp[ind][prev]!=-1)
           return dp[ind][prev];


     int mncost=INT_MAX;

    for(int i=0;i<3;i++)
    {
       if(i!=prev){

        int val=col[ind][i]+f(ind-1,i,col,dp);

        mncost=min(mncost,val);

      }


    }

     return dp[ind][prev]=mncost;
}


void solve(){

         ll a1,a2,b,l,r,c,n,m,p,x,y=0,z,s=0,Ts=0,cnt=0,mx=0,ok=0,ya=0;
           string st;
           cin>>n;

     // vector<ll>v(n);
     // vector<ll>id(n+1,0);


      int col[n][3];
       for(int i=0;i<n;i++)
       for(int j=0;j<3;j++)
        cin>>col[i][j];


     vector< vector<int> >dp(n,vector<int>(4,-1));

     cout<<f(n-1,3,col,dp)<<endl;





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