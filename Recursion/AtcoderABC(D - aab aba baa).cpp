    #include "bits/stdc++.h"
#define filei {freopen("c_c++_intput.txt", "r", stdin);}
#define fileo {freopen("c_c++_output.txt", "w", stdout);}

#define FIO  { ios::sync_with_stdio(false);cin.tie(0);}

#define int long long
#define ll long long
//__builtin_popcount
//cerr
#define mod 1000000007
#define amax 1000005

using namespace std ;
// using  lll =   signed __int128;
int fa = 0;
int fb = 0;
string ans = "";


ll ncr(ll n, ll r){
  ll res = 1;
  for(ll i = 0; i < r; i++){
    res *= (n-i);
    res /= (i+1);
  }

  return res;
}

void per (int a , int b , int k)
{
  if (a == 0LL &&  b == 0LL)
  {
    return;
  }

  int left = (a == 0) ? 0 : ncr (a + b - 1,a - 1);
  int right = (b == 0) ? 0 : ncr(a + b - 1,b - 1);


  if (k <= left)
  {
    ans += 'a';
     per (a - 1,b,k );
  }
  else
  {
    ans += 'b';
     per (a , b - 1,k - left);
  }
  return ;
}
signed main ()
{
    FIO
    int t;


    t = 1;
    for (int loop = 1; loop <= t; loop++)
    {
      int a,b,k ;
      cin >> a >> b >> k ;
       per (a,b,k);

      cout << ans << "\n";

  }

}


