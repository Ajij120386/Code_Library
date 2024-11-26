#include<bits/stdc++.h>
using namespace std;


int main()
{

        string s;
        char c;
        cin >> c;
        getline ( cin, s );
        s = c + s;

        string tmp;

        vector<string> v; /// the devil in the sky

        for ( auto u : s ) {

            if ( isspace( u ) ) {
                v.push_back ( tmp );
                tmp.clear();
            }

            else tmp += u;
        }

        v.push_back ( tmp );

        reverse(v.begin(),v.end());

        for(auto it: v) cout<<it<<" ";

        cout<<endl;



}

