#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5;
const ll inf = 1e9;

template<typename A, typename B> istream & operator >> (istream &is, pair<A,B> &_z) { return is >> _z.first >> _z.second; }
template <typename A, typename B> ostream & operator << (ostream &os, const pair<A,B> &_z) { return os << "(" << _z.first << ", " << _z.second << ")"; }
template <typename T> istream & operator >> (istream &is, vector<T> &_zz) { for (auto &__ : _zz) is >> __; return is; }
template <typename T> ostream & operator << (ostream &os, const vector<T> &_zz) { os << "["; for (int i = 0 ;i < _zz.size(); i++) { if (i) os << ", "; os << _zz[i]; } os << "]"; return os; }

int n, cont = 0;
vector<int> ar;

void merge_sort(int l, int r) {
    if (l == r) return;

    int m = (l + r) >> 1;
    merge_sort(l, m);
    merge_sort(m+1, r);

    int minlef = ar[l];
    int maxrig = ar[r];

    if (minlef > maxrig) {
        cont++;
        int mid = (r-l)>>1;
        for (int i = 0 ;i <= mid; i++) swap(ar[l+i], ar[m+1+i]);
    }
}

bool sorted (vector<int> &ar) {
    for (int i = 1 ;i < ar.size(); i++)
        if (ar[i-1] > ar[i])
            return false;
    return true;
}

int main () {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        ar.resize(n); cin >> ar;
        cont = 0;
        merge_sort(0, n-1);
        int ans = sorted(ar)? cont : -1;
        cout << ans << endl;

    }
    return 0;
}
