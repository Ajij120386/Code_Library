

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {


       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());

       int n=arr.size();
       int i=1,j=0,availablePlat=1,mxPlat=1;


       while(i<n && j<n)
       {

            if(arr[i]<= dep[j])  //one more platform needed
            {
                availablePlat++;
                i++;
            }
            else{   //one platform can be reduced

                availablePlat--;
                j++;

            }

           mxPlat=max(mxPlat,availablePlat);
       }
       return mxPlat;
    }
};


