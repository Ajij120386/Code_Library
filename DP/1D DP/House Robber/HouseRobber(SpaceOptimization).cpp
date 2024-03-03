

#include<bits/stdc++.h>
using namespace std;

int  f(vector<int>&arr)
{
    int n=arr.size();
    int prev=arr[0];
    int prev2=0;

 for(int i=1;i<n;i++)
{
      int pick =arr[i];

        if(i>1)
               pick+=prev2;

       int notpick =prev + 0;

       int cur= max(pick,notpick);
       prev2=prev;
       prev=cur;
 }
   return prev;
}
int main(){

  int n,x;
  cin>>n;
  int arr[n+1];
   for(int i=0;i<n;i++){

        cin>>arr[i];
  }

   vector<int>arr1,arr2;

 if(n==1) return arr[0];
  for(int i=0;i<n;i++){
        if(i!=n-1)
         arr1.push_back(arr[i]);
         if(i!=0)
         arr2.push_back(arr[i]);
  }


 int Firsthalf=f(arr1);

 int Secondhalf=f(arr2);

  cout<<max(Firsthalf,Secondhalf)<<endl;

}




