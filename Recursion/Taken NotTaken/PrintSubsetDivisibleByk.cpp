
#include<bits/stdc++.h>

using namespace std;

    void func(int ind, vector < int > &ds, int sum, int arr[],int n,int k)
     {
         if (ind == n)
            {
                if(ds.size()!=0 && sum%k==0)
                 {
                     for(auto it: ds)
                    {
                      cout<<it<<" ";
                    }
                 cout<<endl;
                 }
                  return;
            }


      //element is picked
      ds.push_back(arr[ind]);
      sum+=arr[ind];
      func(ind + 1, ds,sum,arr, n,k);


      //element is not picked
        ds.pop_back();
        sum-=arr[ind];
        func(ind + 1, ds,sum,arr, n,k);
    }


int main() {

   int arr[] = {4,3,2};

 vector<int>ds;

    func(0,ds,0,arr,3,3);


  return 0;
}
