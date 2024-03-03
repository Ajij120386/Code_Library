//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int n) {

           long long l=1,r=n-1,mid,ans;

           while(l<=r)
           {
               mid=(l+r)/2;

               if(mid*mid<=n-1)
               {
                    ans=mid;
                    l=mid+1;
               }
               else
               {
                    r=mid-1;
               }
           }
           return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
