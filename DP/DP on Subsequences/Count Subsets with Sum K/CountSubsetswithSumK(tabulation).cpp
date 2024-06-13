class Solution{
public:



    bool isSubsetSum(vector<int>arr, int sum){

        int n=arr.size();


        vector< vector<int> >dp(n, vector<int>(sum+1,0));

        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }

        if(arr[0]<=sum) dp[0][arr[0]]=true;


        for(int ind=1;ind<n;ind++)
        {
             for( int tar=1;tar<=sum;tar++)
             {

                 bool nottake=dp[ind-1][tar];

                 bool take=false;

                 if(arr[ind]<=tar)

                    take= dp[ind-1][tar-arr[ind]];

                dp[ind][tar]=nottake||take;
             }

         }



        return dp[n-1][sum];
    }
};
