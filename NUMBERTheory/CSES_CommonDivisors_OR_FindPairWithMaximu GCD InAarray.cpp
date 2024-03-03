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



     int n,mx=0,ans=0;
    cin>>n;

  int ar[n+1];

 map<int,int>mp;
   for(int i=1;i<=n;i++)
   {
    cin>>ar[i];
    mx=max(ar[i],mx);
    mp[ar[i]]++;

   }
int cnt=0;

   for(int i=mx;i>=1;i--){

   cnt=0;

         for(int j=i;j<=mx;j+=i){

         cnt+=mp[j];

            if(cnt>=2){

                cout<<i<<endl;
                 return;
            }

    }


   }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
