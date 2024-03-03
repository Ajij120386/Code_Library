


#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&val,vector<int>&wt,int W)
{
         if(ind==0)
         {
                if(wt[0]<=W)
                    return val[0];

             return 0;
         }

         int nottake =  0 +f(ind-1,val,wt,W) ;

      int  take=INT_MIN;
      if(wt[ind]<=W)
                take =  val[ind]+f(ind-1,val,wt,W-wt[ind]) ;


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
4 5
1 2 4 5
5 4 8 6
*/


