
#include<bits/stdc++.h>

using namespace std;

    int CountSubset(int ind, int sum,int arr[],int n,int k)
     {
         if (ind == n)
            {
                if(sum%k==0)
                   return 1;

              else
                  return 0;
            }


      //element is picked
      sum+=arr[ind];
     int l= CountSubset(ind + 1, sum,arr,n,k);


      //element is not picked

        sum-=arr[ind];
       int r= CountSubset(ind + 1, sum,arr, n,k);

       return l+r;
    }


int main() {

   int arr[] = {4,3,2};


   int cnt= CountSubset(0,0,arr,3,3);

   //empty set is also included

cout<<cnt-1<<endl;
  return 0;
}

