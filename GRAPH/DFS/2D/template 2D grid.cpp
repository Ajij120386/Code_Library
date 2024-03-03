
/******* BISMILLAHIR RAHMANIR RAHIM *******/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//TypeDEfN
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;



typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;

//Constants

const ll INF= LONG_LONG_MAX;
const ll mod=1e9+7;

// Macros
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define fio(i,n) for(int i=1;i<=n;i++)
#define fiz(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n;i>=0;i--)
#define co(n) cout<<n<<endl
#define coy cout<<"Yes"<<endl
#define con cout<<"No"<<endl
#define ci(n) cin>>n
#define w(x) while(x--)
#define ci2(a,b) cin>>a>>b
#define ci3(a,b,c) cin>>a>>b>>c

#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rvs(v) reverse(v.begin(),v.end());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 1005;


int vis[N][N];
char grid[N][N];
int n,m,sr,sc,cnt;


int dr[] ={-1,1,0,0,-1,-1,1,1};
int dc[] ={0,0,-1,1,-1,1,-1,1};

void dfs(int r,int c)
{



        vis[r][c]=1;

        for(int i=0;i<4;i++)
        {

         int nr=r+dr[i];
         int  nc=c+dc[i];

              if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='.' && !vis[nr][nc])
              {

                  dfs(nr,nc);

              }

        }

    }


bool valid(int x,int y){

   return(x>=0 && y>=0 && x<n && y<m && !vis[x][y]);

}

void reset(int r,int c)
{

  for(int i=0;i<r;i++)
  {
   for(int j=0;j<c;j++)
   {

    vis[i][j]=0;
    }
  }
}

    void solve(){



       cin>>n>>m;

       reset(n,m);

           for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){

                  cin>>grid[i][j];

                }
           }





         for(int row = 0; row < n ; row++) {
              for(int col = 0; col < m ;col++) {


                if(!vis[row][col] && grid[row][col] == '.')

                {
                    // cout<<row<<" "<<col<<endl;
                       cnt++;
                       dfs(row, col);
                }
            }
        }


    cout << cnt << endl;



      }



int main(){

fastio;

int t=1,tc=1;
///ci(t);

w(t){



//cout<<"Case "<<tc++<<": ";
   solve();


}
}



