
#include<bits/stdc++.h>
const int mod=1000000007;
const int MX = 1e7+5;
#define  pf                 printf
#define  sc                 scanf

#define  s1(n)              scanf("%d",&n)
#define  s2(n1,n2)          scanf("%d %d",&n1,&n2)
#define  s3(n1,n2,n3)       scanf("%d %d %d",&n1,&n2,&n3)
#define  s4(n1,n2,n3,n4)    scanf("%d %d %d %d",&n1,&n2,&n3,&n4)

#define  ss1(n)             scanf("%lld",&n)
#define  ss2(n1,n2)         scanf("%lld %lld",&n1,&n2)
#define  ss3(n1,n2,n3)      scanf("%lld %lld %lld",&n1,&n2,&n3)
#define  ss4(n1,n2,n3,n4)   scanf("%lld %lld %lld %lld",&n1,&n2,&n3,&n4)

#define  p1(x)              printf("%I64d",x)
#define  p2(x,y)            printf("%I64d %I64d",x,y)
#define  p3(x,y,z)          printf("%I64d %I64d %I64d",x,y,z)

#define  f0(i , a)          for(long long i=0; i<a;i++)
#define  f1(i , a)          for(long long i=1;i<=a;i++)

#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define  clr(x)             memset(x,0,sizeof(x))
#define  cln(x)             memset(x,-1,sizeof(x))
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define pi  acos(-1)
using namespace std;


vector < int > v1,v2;

void one_count(int value){
    //count binary bit one
 for (int bit = 0; bit < 30; bit ++) {
    int k =(value>>bit)&1;
    v1.pb(k);
   }
}
void half(int value){
    //count binary bit one
 for (int bit = 0; bit < 30; bit ++) {
    int k =(value>>bit)&1;
    v2.pb(k);
   }
}
/*
   xor propartiese
   a^b=x;
   x^b=a;
   a^x=b;
*/

/*priority_queue< int, vector<int>, greater<int> >q; */

signed main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
       int x;
       cin>>x;
       one_count(x);
       half(x/2);
       reverse(v1.begin(),v1.end());
       reverse(v2.begin(),v2.end());
       /*for(auto u:v1) cout<<u<<" ";
        cout<<endl;
        for(auto u:v2) cout<<u<<" ";
            cout<<endl;*/
       int flg = 0;
       for(int i=0; i<v1.size(); i++)
        {
            if(v1[i]==v2[i] and v1[i]!=0) flg = 1;
        }
        if(flg or x&1) cout<<"-1"<<endl;
        else cout<<x+x/2<<" "<<x/2<<endl;
        v1.clear();
        v2.clear();
    }
    /********  Alhamdulilha **********/
    return 0;
  }
