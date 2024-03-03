
#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,x;
  cin>>n;

    vector<int>heights;

  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }

 int prev=0;
   int prev2=0;

 for(int i=1;i<n;i++){

        int jumpOne =prev+ abs(heights[i]-heights[i-1]);

       int jumpTwo= INT_MAX;

      if(i>1)

       jumpTwo =prev2+ abs(heights[i]-heights[i-2]);

       int cur= min(jumpOne,jumpTwo);
        prev2=prev;
         prev=cur;
 }
   cout<<prev<<endl;
}


