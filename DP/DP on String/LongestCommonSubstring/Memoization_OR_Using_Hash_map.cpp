#include<bits/stdc++.h>
using namespace std;
int f(string &s1, string &s2,int ind1,int ind2,int count, map<string,int>&mp)
{


 if(ind1<0 || ind2<0)
   return count;

   string key=to_string(ind1) + "Ajij" + to_string(ind2) + "Bro" +to_string(count);

 if(mp.find(key)!=mp.end())
       return mp[key];

 if(s1[ind1]==s2[ind2])
    count= f(s1,s2,ind1-1,ind2-1,count+1,mp);

    count= max(count,max(f(s1,s2,ind1-1,ind2,0,mp),f(s1,s2,ind1,ind2-1,0,mp)));


  return mp[key]= count;

}
int lcs(string &str1, string &str2){

    int n=str1.size();
    int m=str2.size();

    map<string,int>mp;

    return f(str1,str2,n-1,m-1,0,mp);
    // Write your code here.

}
