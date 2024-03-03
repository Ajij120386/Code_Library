
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&val,int T)
{
         if(ind==0)
         {
             return (T%val[0]==0);

         }

         int nottake =  f(ind-1,val,T) ;

         int  take=0;

      if(val[ind]<=T)
                take =  f(ind,val,T-val[ind]) ;


return take+nottake;

}
int main(){

  int n,W,T,x;
  cin>>n>>T;
   vector<int>val;

 for(int i=0;i<n;i++)
    {
          cin>>x;
          val.push_back(x);

    }

  cout<<f(n-1,val,T)<<endl;

}
/*
3 4
1 2 3
*/


