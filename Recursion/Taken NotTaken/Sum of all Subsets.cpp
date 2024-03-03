
#include<bits/stdc++.h>

using namespace std;

 void FindSubsetSum(int ind, int sum,int arr[],vector<int>&subsetsum,int n)
     {
         if (ind == n )
            {
                if(sum!=0)
                    subsetsum.push_back(sum);
                   return;

            }


      //element is picked
      sum+=arr[ind];
     FindSubsetSum(ind + 1, sum,arr,subsetsum,n);


      //element is not picked

        sum-=arr[ind];
        FindSubsetSum(ind + 1, sum,arr,subsetsum, n);


    }


int main() {

   int arr[] = {4,3,2};
   int n=3;

vector<int>subsetsum;
  FindSubsetSum(0,0,arr,subsetsum,n);

for(auto it: subsetsum) cout<<it<< " ";
  return 0;
}


