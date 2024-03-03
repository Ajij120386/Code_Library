#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector < int > & nums, vector < int > & subarray) {

    int maxsum=INT_MIN,currentmaxsum=0;
    int s = 0;

   for(int i=0;i<nums.size();i++){

    currentmaxsum+=nums[i];

    if(currentmaxsum>maxsum){

        maxsum=currentmaxsum;
          subarray.clear();
           subarray.push_back(s);
            subarray.push_back(i);
    }

    if(currentmaxsum<0){
        currentmaxsum=0;
        s=i+1;
    }


   }

    return maxsum;
}


int main() {

    int n;
    cin>>n;
    vector < int > subarray;
      vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++) {
        cout << arr[i] << " ";
    }

}

/*

input: {-2,1,-3,4,-1,2,1,-5,4};
The longest subarray with maximum sum is: 6
The subarray is: 4 -1 2 1
*/
