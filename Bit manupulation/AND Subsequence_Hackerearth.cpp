
/*
You are given an array having integers and an integer . Find the length of the longest non-empty subsequence of the array
 such that the Bitwise AND of the elements of the subsequence is greater than or equal to
  Print if no such subsequence exists.

  input:
1
6 9
7 12 13 15 14 13

output:5
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 1000000007
#define BINF 1e16
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 10000005
#define deb(xx) cout << #xx << " " << xx << "\n";
const int LG = 22;


void solve() {

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int c = 0, l = 0;

    int bit = log2(x);
    /*
    for(int i = 30; i >= 0; i--) {
        if((x & (1LL << i)) > 0) {
            bit = i;
            break;
        }
    }
*/
    for(int i = 30; i > bit; i--) {
        l = 0;
        for(int j = 0; j < n; j++) {
            if((v[j] & (1LL << i)) > 0) {
                l = l + 1;
            }
        }

            c = max(c, l);

    }

    vector<int> arr;
    for(int i = 0; i < n; i++) {
        arr.push_back(v[i]);
    }

    for(int i = bit; i >= 0; i--) {
        vector<int> t;
        for(auto j : arr) {
            if((j & (1LL << i)) > 0) {
                t.push_back(j);
            }
        }

        if((x & (1LL << i)) > 0) {
            arr = t;
        }
         else {
            int len = t.size();

                c = max(c, len);

        }
    }

    int len = arr.size();

        c = max(c, len);

if(c==0) c=-1;
    cout << c << endl;

}


#undef int
int main() {
#define int long long int
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);


    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

return 0;

}

