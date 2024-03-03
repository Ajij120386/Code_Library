#include<bits/stdc++.h>

using namespace std;

    vector<vector< int > >subsetFind(vector<int>&v,int n)
   {

       vector<vector<int> >Allsubset;
             for(int mask=1;mask<(1<<n);mask++)
            {
                vector<int>subset;
                     for(int i=0;i<n;i++)
                   {
                       if((1<<i)&mask)
                       {
                          subset.push_back(v[i]);
                       }

                    }
                    Allsubset.push_back(subset);
            }
            return Allsubset;
    }

int main() {

   int n,x;
   cin>>n;
 vector<int>v;
 for(int i=0;i<n;i++)
 {
     cin>>x;
     v.push_back(x);
 }

vector<vector<int> >ans=subsetFind(v,n);


for(auto it: ans)
{
    for(auto x: it)
    cout<<x<<" ";
    cout<<endl;
}

  return 0;
}

