
#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector< int> &arr,int T)
{
    /*
          //when our array constraint 1<=arr[i],then this base case will use

        if(T==0)
               return 1;

         if(ind==0)
                  return (arr[ind]==T)

    */

     //when our array constraint 0<=arr[i], then this base case will use

        if(ind==0){

                if(T==0 && arr[0]==0)
                         return 2;
                if(T==0 || T==arr[0])
                       return 1;

                       return 0;
        }
          int nottake =  f(ind-1,arr,T);
          int take =0;
      if(arr[ind]<=T)
               take =  f(ind-1,arr,T-arr[ind]);

  return  take+nottake;


}
int main(){
  int n,m,x,row,col,TotalSum=0,d,D;

  cin>>n>>d;

  vector< int>arr;
   for(int i=0;i<n;i++)
 {

        cin>>x;
       arr.push_back(x);
     TotalSum+=x;

    }
    if(TotalSum-d<0){
       cout<<0<<endl;
       return 0;
   }
    if((TotalSum-d)%2){
       cout<<0<<endl;
       return 0;
   }
   int target=(TotalSum-d)/2;
   cout<<f(n-1,arr,target)<<endl;

}
