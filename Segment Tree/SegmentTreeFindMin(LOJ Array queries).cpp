#include<bits/stdc++.h>
using namespace std;
#define mx 100007
int ar[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {

       tree[node]=ar[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
     int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=min(tree[Left],tree[Right]);

}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) //বাইরে চলে গিয়েছে
         return 1e9;
    if(b>=i && e<=j) //রিলেভেন্ট সেগমেন্ট
        return tree[node];

                       //noito আরো ভাঙতে হবে
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
     return min(p1,p2); //বাম এবং ডান পাশের যোগফল

}

int main()
{

   int t,tc=1;
   cin>>t;
   while(t--)
   {
            cout<<"Case "<<tc<<":" <<endl;
      int n,q;
      cin>>n>>q;

tc++;
      for(int i=1;i<=n;i++)
      {
          cin>>ar[i];
       }

       init(1,1,n);
      for(int i=0;i<q;i++)
      {
          int l,r;
          cin>>l>>r;

           cout<<query(1,1,n,l,r)<<endl;
       }

   }
}
