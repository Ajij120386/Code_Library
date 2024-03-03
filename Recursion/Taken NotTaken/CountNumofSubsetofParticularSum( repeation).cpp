// ****************beg---------------------end*****************



#include<bits/stdc++.h>

using namespace std;

    int CountSubset(int ind, int sum,int arr[],int n)
     {
         if (ind == n)
            {
                if(sum==0)
                   return 1;

              else
                  return 0;
            }


         int l=0,r=0;

      //element is picked
      if(arr[ind]<=sum){
           sum-=arr[ind];   //sum will decrease
            l= CountSubset(ind , sum,arr,n);
            sum+=arr[ind];   //restore sum
      }

      //element is not picked
     r= CountSubset(ind + 1,sum,arr,n);

       return l+r;
    }


int main() {

   int arr[] = {1,2};
    int k=2;

   int cnt= CountSubset(0,2,arr,2);

   //empty set is also included

cout<<cnt<<endl;
  return 0;
}

//***********************end to start ****************

/*
#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector< int> &arr,int T)
{

        if(T==0)
               return 1;

         if(ind<0) return 0;



          int nottake =  f(ind-1,arr,T);
          int take =0;
      if(arr[ind]<=T)
               take =  f(ind,arr,T-arr[ind]);

  return  take+nottake;


}
int main(){

  int n=6,m,x,row,col,T;
  cin>>T;

  vector< int>arr={1,2,3,4,5,6};


   cout<<f(n-1,arr,T)<<endl;

}




/*

1 1 1 1 1
1 1 1 2
1 1 3
1 2 2
1 4
2 3
5

7
*/


