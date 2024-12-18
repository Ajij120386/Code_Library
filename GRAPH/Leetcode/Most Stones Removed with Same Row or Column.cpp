
class Solution {
public:

int n;
 void dfs(int ind, vector<int> & vis,vector<vector<int>>& stones)
 {

     vis[ind]=1;

     for(int i=0;i<n;i++)
     {
        int r=stones[i][0];
        int c=stones[i][1];
        if(!vis[i] && (r==stones[ind][0] || c==stones[ind][1]) )

        {
                 dfs(i,vis,stones);
        }
     }

 }


    int removeStones(vector<vector<int>>& stones) {

         n=stones.size();
         int cnt=0;

         vector<int>vis(n,0);

      for(int i=0;i<n;i++)
      {
        if(!vis[i])
        {
             dfs(i,vis,stones);
              cnt++;
        }

      }

        return n-cnt;

    }
};
