#include<bits/stdc++.h>

using namespace std;

long long Swap(string s,int n)
{

    if(n==2)
        return stoll(s);

    long long mx=0;
    for(int i=0;i<s.size();i++)
     {

        for(int j=i+1;j<s.size();j++)
         {
            string ss=s;
            swap(ss[i],ss[j]);
            mx=max(mx,Swap(ss,n+1));

         }
      }
      return mx;
}
int main(){

int t;
cin>>t;
while(t--){
    long long n;
    cin>>n;
    string s=to_string(n);
    cout<<Swap(s,0)<<endl;
}
}
