
#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int main()
{


    int t;
    cin>>t;
    while(t--)
    {

        int n,C;
        cin>>n>>C;

        vector<int> stalls;
        for(int i=0;i<n;i++)
        {
            int x;
           cin>>x;
           stalls.push_back(x);
        }

         //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:


        while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, C) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }


    cout<<high<<endl;


    }
}
