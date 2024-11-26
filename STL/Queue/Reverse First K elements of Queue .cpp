
#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}
queue<ll> modifyQueue(queue<ll> q, int k)
{

    stack<ll> st;
    queue<ll> ret;

    while ( k-- ) {
        st.push ( q.front() );
        q.pop();
    }

    while ( !st.empty() ) {
        ret.push ( st.top() );
        st.pop();
    }

    while ( !q.empty() ) {
        ret.push ( q.front() );
        q.pop();
    }

    return ret;


}
