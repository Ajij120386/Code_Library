
#include<bits/stdc++.h>
using namespace std;

bool f(int ind, vector< int> &arr,int T)
{
        if(T==0)
               return true;
         if(ind==0)
                 return (arr[ind]==T);

          bool nottake =  f(ind-1,arr,T);
          bool take =false;
      if(arr[ind]<=T)
               take =  f(ind-1,arr,T-arr[ind]);

  return  take || nottake;


}
int main(){

  int n,m,x,row,col,TotalSum=0;
  cin>>n;

  vector< int>arr;
   for(int i=0;i<n;i++)
 {

        cin>>x;
       arr.push_back(x);
        TotalSum+=x;

 }
   if(TotalSum%2){
       cout<<0<<endl;
       return;
   }
   int target=TotalSum/2;
   cout<<f(n-1,arr,target)<<endl;

}





