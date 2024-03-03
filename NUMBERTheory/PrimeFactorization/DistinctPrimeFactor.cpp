/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Incomplete

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

#define N 200009
vector<int> primefactor[N];
vector<int> cnt(N);

void solve() {


    for (int i = 2; i <= N; i++) {
        if (primefactor[i].empty()) {

            for (int j = i; j <= N; j += i) {
                primefactor[j].push_back(i);
            }
        }
    }

   for(int i=2;i<=20;i++)
   {
       cout<<i<<"--->";

       for(auto it: primefactor[i])
        cout<<it<<" ";

       cout<<endl;
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
