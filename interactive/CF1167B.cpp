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


    set<int>num={4,8,15,16,23,42};
    vector<int>v;
    int a=interact(1,2);
    int b=interact(2,3);
    int c=interact(4,5);
    int d=interact(5,6);



    for(auto it: num){
        if(a%it==0 && b%it==0){
                int s1=a/it;
                int s2=b/it;
                if(s1!=it && s2!=it && num.count(s1)==1 && num.count(s2)==1 )
                {
                    v.push_back(s1);
                    v.push_back(it);
                    v.push_back(s2);
        break;
                }


        }
    }

   for(auto it: num){
        if(c%it==0 && d%it==0){
                int s1=c/it;
                int s2=d/it;
                 if(s1!=it && s2!=it && num.count(s1)==1 && num.count(s2)==1 )
                {
                    v.push_back(s1);
                    v.push_back(it);
                    v.push_back(s2);
        break;
                }


        }
    }
    cout<<"! ";
    for(auto i : v) cout<<i<<" ";
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

