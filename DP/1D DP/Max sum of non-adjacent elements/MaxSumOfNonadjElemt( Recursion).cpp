
#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&arr)
{
         if(ind==0) return arr[ind];

          if(ind<0) return 0;

      int pick =f(ind-2,arr)+ arr[ind];

      int notpick =f(ind-1,arr)+ 0;


return max(pick,notpick);

}
int main(){

  int n,x;
  cin>>n;
   vector<int>arr;
  for(int i=0;i<n;i++){
        cin>>x;
     arr.push_back(x);
  }

  cout<<f(n-1,arr)<<endl;

}

