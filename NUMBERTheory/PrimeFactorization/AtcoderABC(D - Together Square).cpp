
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

#define N 200009
vector<int> arr[N];
vector<int> cnt(N);

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= N; i++) {
        if (arr[i].empty()) {
            for (int j = i; j <= N; j += i) {
                arr[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; i++){

        int val = 1;
        int temp = i;
        for (auto x : arr[i]) {
            int cal = 0;
            while (temp % x == 0) {
                temp /= x;
                cal++;
            }
            if (cal %2) val *= x;
        }
        cnt[val]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i] * cnt[i];
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
