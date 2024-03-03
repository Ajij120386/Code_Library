
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&price,int N)
{
         if(ind==0)
         {
             return N*price[0];
         }

         int nottake =  0 +f(ind-1,price,N) ;

      int  take=INT_MIN;
      int rodlength=ind+1;
      if(rodlength<=N)
                take =  price[ind]+f(ind,price,N-rodlength) ;


return max(take,nottake);

}
int main(){

  int n,W,x;
  cin>>n;
   vector<int>price;
  for(int i=0;i<n;i++)
    {
        cin>>x;
        price.push_back(x);

    }


  cout<<f(n-1,price,n)<<endl;

}
/*
5
2 5 7 8 10
*/



