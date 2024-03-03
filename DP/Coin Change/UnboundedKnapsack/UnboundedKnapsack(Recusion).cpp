#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&val,vector<int>&wt,int W)
{
         if(ind==0)
         {
             return (W/wt[0])*val[0];
         }

         int nottake =  0 +f(ind-1,val,wt,W) ;

      int  take=INT_MIN;
      if(wt[ind]<=W)
                take =  val[ind]+f(ind,val,wt,W-wt[ind]) ;


return max(take,nottake);

}
int main(){

  int n,W,x;
  cin>>n>>W;
   vector<int>wt,val;
  for(int i=0;i<n;i++)
    {
        cin>>x;
        wt.push_back(x);

    }
 for(int i=0;i<n;i++)
    {
          cin>>x;
          val.push_back(x);

    }

  cout<<f(n-1,val,wt,W)<<endl;

}
/*
3 10
2 4 6
5 11 13
*/



