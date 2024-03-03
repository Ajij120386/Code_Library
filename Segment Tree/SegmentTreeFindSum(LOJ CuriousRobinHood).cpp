#include<bits/stdc++.h>
using namespace std;
#define mx 100001
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
    tree[node]=tree[Left]+tree[Right];

}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) //বাইরে চলে গিয়েছে
         return 0;
    if(b>=i && e<=j) //রিলেভেন্ট সেগমেন্ট
        return tree[node];

                       //noito আরো ভাঙতে হবে
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
     return p1+p2; //বাম এবং ডান পাশের যোগফল

}
void update(int node,int b,int e,int i,int newValue)
{
    if(i>e || i<b) //বাইরে চলে গিয়েছে
         return;
    if(b>=i && e<=i) //রিলেভেন্ট সেগমেন্ট
      {
          tree[node]+=newValue;
          return;
      }

                       //noito আরো ভাঙতে হবে
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newValue);
    update(Right,mid+1,e,i,newValue);

     tree[node]=tree[Left]+tree[Right];

}
void update1(int node,int b,int e,int i,int newValue)
{
    if(i>e || i<b) //বাইরে চলে গিয়েছে
         return;
    if(b>=i && e<=i) //রিলেভেন্ট সেগমেন্ট
      {
          cout<<tree[node]<<endl;
          tree[node]=0;
          return;
      }

                       //noito আরো ভাঙতে হবে
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update1(Left,b,mid,i,newValue);
    update1(Right,mid+1,e,i,newValue);

     tree[node]=tree[Left]+tree[Right];

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
    {   int a,b,c;
          cin>>a;
          if(a==1)
          {
              cin>>b;
              b++;
            update1(1,1,n,b,0);
          }
         else if(a==2)
          {
              cin>>b>>c;
              b++;
            update(1,1,n,b,c);
          }

            else
          {
              cin>>b>>c;
              b++,c++;
     cout<<query(1,1,n,b,c)<<endl;

          }
   }
   }
}
