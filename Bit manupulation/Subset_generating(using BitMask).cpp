
///////////////////// Subsets//////////////////////////////////////

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();

         vector<vector<int>> res;

         for(int i=0;i<=(1<<n)-1;i++)
         {
            vector<int>temp;

            for(int j=0;j<n;j++)
            {

                if(i & (1<<j)){

                    temp.push_back(nums[j]);
                }
            }

            res.push_back(temp);
         }
        return res;
    }
};


//////////////////////////////////////////////

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

