//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    double floorSqrt(long long int x)
    {
        // Your code goes here
        double l=0,r=x;
        for(int i=0;i<100;i++){

            double mid=(l+r)/2.00;
            if(mid*mid>x) r=mid;
            else l=mid;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		double val= obj.floorSqrt(n);
		cout << setprecision(9);
		cout<<val << endl;
	}
    return 0;
}

// } Driver Code Ends
