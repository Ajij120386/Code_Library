#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int interact(int i , int j){
    cout<<"? "<<i<<' '<<j<<endl;
    int x;
    cin>>x;
    return x;
}

void solve(){
    int n;
    cin>>n;
    int a=interact(1,3);
    int b=interact(1,2);
    int c=interact(2,3);
    vector<int>num(n);
    num[0]=a-c;
    num[2]=a-b;
    num[1]=a-num[0]-num[2];
    for(int i=3;i<n;i++){
        int x=interact(i,i+1);
        num[i]=x-num[i-1];
    }
    cout<<"! ";
    for(auto i : num) cout<<i<<" ";
    return;
}
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);

            int t=1;
            // cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";
                solve();
    }
    return 0;
}
