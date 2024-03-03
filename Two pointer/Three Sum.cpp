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


/*

    Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the
    output does not count towards the space complexity.

    Solved using Array(Two Nested Loop) + Sorting. Optimized Approach.

*/
 vector<vector<int>> threeSum(vector<int>& num) {

        vector<vector<int>> res;
        sort(num.begin(), num.end());
int n=num.size();
        // moves for a
        for (int i = 0; i < n-2; i++) {



                int lo = i+1, hi = n-1, sum = 0 - num[i];

                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {

                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[lo]);
                        temp.push_back(num[hi]);
                        res.push_back(temp);

                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;

                        lo++; hi--;
                    }
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
               while(i+1<n && num[i]==num[i+1]) i++;
            }

        return res;
    }

void solve(){

         ll a1,a2,b,r,c,n,m,p,q,x,y,z,s=0,Ts=0,cnt=0,mx=0,ok=0,ya=0;
           string st;
           ci(n);
      vector<int>v(n);

       for(int i=0;i<n;i++)
    {
        cin>>v[i];
     }

      vector<vector<int>> ans=threeSum(v);

      for(auto it: ans){

          for(auto it2: it){

              cout<<it2<<" ";
          }
          cout<<endl;
      }



}



int main(){

fastio;

int t=1,tc=0;
//cin>>t;

for(int i=1;i<=t;i++){

            //    cout<<"Case #"<<i<<": ";
                solve();


}
}
/*****************  ALHAMDULILLAH  *****************/

/*
input:
11
-2 -2 -1 -1 -1 0  0 0 2 2 2
output:
-1 -1 2
-2 0 2
0 0 0
*/






/*

    Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(N), Hash Table(set) space.

    Solved using Array(Two Nested Loop) + Sorting + Hash Table(set).


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};
*/
