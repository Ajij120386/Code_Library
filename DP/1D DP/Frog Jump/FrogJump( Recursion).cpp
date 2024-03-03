#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&heights)
{
         if(ind==0) return 0;

      int jumpOne =f(ind-1,heights)+ abs(heights[ind]-heights[ind-1]);

       int jumpTwo= INT_MAX;
      if(ind>1)

       jumpTwo =f(ind-2,heights)+ abs(heights[ind]-heights[ind-2]);


return min(jumpOne,jumpTwo);

}
int main(){

  int n,x;
  cin>>n;
   vector<int>heights;
  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }

  cout<<f(n-1,heights)<<endl;

}

