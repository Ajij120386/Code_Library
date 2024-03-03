#include<bits/stdc++.h>
using namespace std;

int  f(int n,vector< vector< int> >&points)
{

     vector< vector< int> > dp(n+1,vector<int>(4,0));


  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

       for(int day=1;day<n;day++)
      {
           for(int last=0;last<4;last++)
           {
               dp[day][last]=0;
                for(int task=0;task<3;task++)
              {


                 if(task!=last)
                 {
                     int point = points[day][task] + dp[day-1][task];

                     dp[day][last]=max(dp[day][last],point);
                 }
              }

           }
      }

         return dp[n-1][3];



}
int main(){

  int n,x;
  cin>>n;

   vector< vector< int> > points(n+1);


   for(int i=0;i<n;i++)
 {
    for(int j=0;j<3;j++)

   {
        cin>>x;
     points[i].push_back(x);
    }

 }



  cout<<f(n,points)<<endl;

}




