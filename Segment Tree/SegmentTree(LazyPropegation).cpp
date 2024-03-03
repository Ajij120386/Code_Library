  #include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ar[mx];
struct info
{
    int prop,sum;

} tree[mx*3];  //sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ

void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b) //বাইরে চলে গিয়েছে
         return;
    if(b>=i && e<=j) //রিলেভেন্ট সেগমেন্ট or নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
      {
          tree[node].sum+=((e-b+1)*x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
          tree[node].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
          return;
      }

                       //noito আরো ভাঙতে হবে
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);

     tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;

     //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}
int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b) //বাইরে চলে গিয়েছে
         return 0;
    if(b>=i && e<=j) //রিলেভেন্ট সেগমেন্ট
        return tree[node].sum+carry*(e-b+1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

                       //noito আরো ভাঙতে হবে
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    int p1=query(Left,b,mid,i,j,carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    int p2=query(Right,mid+1,e,i,j,carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
     return p1+p2; //বাম এবং ডান পাশের যোগফল

}
int main()
{

}
