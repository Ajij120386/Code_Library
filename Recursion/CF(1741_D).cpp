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

vector<int>v;
int ans=0;
void call(int l1,int r1,int l2,int r2)
{
    int mx=0;

    for(int i=l1;i<=r1;i++)
    {
        mx=max(mx,v[i]);

    }

     int mn=INT_MAX;
    for(int i=l2;i<=r2;i++)
    {
        mn=min(mn,v[i]);

    }

    if(mx>mn)
    {

        int R=l2;

        for(int i=l1;i<=r1;i++)
      {
           swap(v[i],v[R]);
           R++;

      }
        ans++;

    }

    if(l1==r1)
        return;

     int mid1=(l1+r1)/2;
      int mid2=(l2+r2)/2;
    call(l1,mid1,mid1+1,r1);


    call(l2,mid2,mid2+1,r2);


}


void solve(){

         ll a,b,r,c,n,m,p,q,t,x,y,z,s=0,cnt=0,ok=0,ya=0;
           string str;
           cin>>n;
           v.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }

    ans=0;
    if(is_sorted(v.begin()+1,v.end())){

        co(0);
        return;
    }
    int mid=n/2;
    call(1,mid,mid+1,n);

     if(is_sorted(v.begin()+1,v.end()))
    {

        co(ans);

    }
    else
        co(-1);
}
int main(){

fastio;

int t,tc=0;
ci(t);

w(t){

   solve();


}
}
/*****************  ALHAMDULILLAH  *****************/
