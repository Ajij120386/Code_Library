#ifdef ONLINE_JUDGE
#else
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;
using ll=long long;

ll INF=LLONG_MAX;
int inf=INT_MAX;
//const double pi=M_PI;
//const int mod=1000000007;



int main() {
    string S,T;
    cin>>S>>T;
    int N=S.size();
    map<char,set<char>> mp1;
    map<char,set<char>> mp2;
    rep(i,N){
        mp1[S[i]].insert(T[i]);
        mp2[T[i]].insert(S[i]);
    }



    for(auto it:mp1){
        cout<<it.first<<" ";

         for(auto u: it.second){
        cout<<u<<" ";

    }
     cout<<endl;
}


cout<<endl;
cout<<endl;
    for(auto it:mp2){
        cout<<it.first<<" ";

         for(auto u: it.second){
        cout<<u<<" ";

    }
    cout<<endl;
}
    rep(i,N){
        int cnt1=mp1[S[i]].size();
        int cnt2=mp2[T[i]].size();
        if(cnt1!=1||cnt2!=1){

            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;


}
