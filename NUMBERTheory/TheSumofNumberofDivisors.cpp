//In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int SNOD( int n ) {
    int res = 0;
    int u = sqrt(n);
    for ( int i = 1; i <= u; i++ ) {
        res += ( n / i ) - i;
    }
    res *= 2;
    res += u;
    return res;
}
 int main()
{
    optimize();


    int  n;
    cin>>n;
     cout<<SNOD(n)<<endl;

      return 0;
}

