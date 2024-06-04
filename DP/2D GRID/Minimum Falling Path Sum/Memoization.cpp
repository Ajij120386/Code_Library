class Solution {
public:

    int f(int i,int j, vector< vector<int > >&dp,vector<vector<int>>& grid,int m)
   {
            if(j<0 || j>=m)
            return 1e9;
            if(i==0)
               return grid[0][j];

            if(dp[i][j]!=-100000)
            return dp[i][j];

            int up = grid[i][j]+f(i-1,j,dp,grid,m);
            int Leftdiagonal =grid[i][j] + f(i-1,j-1,dp,grid,m);
            int Rightdiagonal =grid[i][j] + f(i-1,j+1,dp,grid,m);

            return dp[i][j]= min ( min(up,Leftdiagonal),Rightdiagonal );

   }

    int minFallingPathSum(vector<vector<int>>& matrix) {

     int n = matrix.size();
         int m = matrix[0].size();

         int mnsum=1e9;

         vector< vector<int > >dp(n, vector<int>(m,-100000));

         for(int i=0;i<m;i++)
         {
               mnsum=min(mnsum, f(n-1,i,dp,matrix,m) );
         }
           return mnsum;

    }
};
