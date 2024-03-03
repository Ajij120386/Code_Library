
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
   vector<int>arr1,arr2;
  for(int i=0;i<n;i++){
        cin>>x;
        if(i!=n-1)
         arr1.push_back(x);
         if(i!=0)
         arr2.push_back(x);
  }

 int Firsthalf=f(n-2,arr1);
 int Secondhalf=f(n-2,arr2);

  cout<<max(Firsthalf,Secondhalf)<<endl;

}


