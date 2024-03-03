#include<bits/stdc++.h>
using namespace std;

int  f(int ind,vector<int>&heights,int k)
{
         if(ind==0) return 0;


      int mmsteps= INT_MAX;

        for(int i=1;i<=k;i++)

      {

           if(ind-i>=0)
          {

            int jump =f(ind-i,heights,k)+ abs(heights[ind]-heights[ind-i]);

            mmsteps=min(jump,mmsteps);
           }

      }
      return mmsteps;
}
int main(){

  int n,x,k;
  cin>>n>>k;
   vector<int>heights;
  for(int i=0;i<n;i++){
        cin>>x;
     heights.push_back(x);
  }

  cout<<f(n-1,heights,k)<<endl;

}

