
#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,x;
  cin>>n;

    vector<int>arr;

  for(int i=0;i<n;i++){
        cin>>x;
     arr.push_back(x);
  }

      int prev=arr[0];
     int prev2=0;

 for(int i=1;i<n;i++){


        int pick =arr[i];
        if(i>1)
               pick+=prev2;

       int notpick =prev+ 0;

       int cur= max(pick,notpick);
       prev2=prev;
       prev=cur;
 }
   cout<<prev<<endl;
}



