
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


