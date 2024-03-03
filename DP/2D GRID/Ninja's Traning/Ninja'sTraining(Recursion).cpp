#include<bits/stdc++.h>
using namespace std;

int  f(int day,int last,vector< vector< int> >&points)
{
         if(day==0)

      {

            int maxi=0;
               for(int task=0;task<3;task++)
             {
                 if(task!=last)
                 {
                     maxi=max(maxi,points[0][task]);
                 }
             }
         return maxi;
     }

           int maxi=0;

               for(int task=0;task<3;task++)
             {
                 if(task!=last)
                 {
                     int point = points [day][task] + f(day-1,task,points);

                     maxi=max(maxi,point);
                 }
             }
         return maxi;



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



  cout<<f(n-1,3,points)<<endl;

}


