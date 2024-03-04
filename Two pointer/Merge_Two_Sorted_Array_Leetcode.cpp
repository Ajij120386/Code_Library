class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1,j=n-1,k=n+m-1;

        while(i>=0 && j>=0)
        {
                if(nums1[i]>nums2[j])
                {
                    nums1[k]=nums1[i];
                    i--;
                    k--;
                }
                else{
                       nums1[k]=nums2[j];
                       j--;
                       k--;

                }

        }
        /*
        If we've exhausted all elements of b, then the only elements left are those of the original array A,
                and they would hence already be in their correct position since A was originally sorted.
  Try the test case     [1,2,3,0,0,0] 3 [4,5,6]  3
        */

        // while(i>=0){

        //        nums1[k--]=nums1[i--];

        // }

        while(j>=0){

               nums1[k--]=nums2[j--];

        }

    }
};
