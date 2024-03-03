#include<bits/stdc++.h>
using namespace std;

bool  check(int i,string s ,int n)
{
       if(n/2<=i) return true;

   if(s[i]==s[n-i-1])
          return check(i+1,s,n);
   return false;



}
int main(){

  int n;
  string s;
  cin>>n>>s;

  bool res=check(0,s,n);

if(res==true)

    cout<<"palindrome"<<endl;
else
cout<<" not palindrome"<<endl;



}




