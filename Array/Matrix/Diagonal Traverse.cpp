

/*
     Input: mat = [
                         [1,2,3]
                         [4,5,6]
                         [7,8,9]
                 ]

       Output: [1,2,4,7,5,3,6,8,9]
*/


//**************************Aproach-------1********************
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> result;

        //fill the map using [i+j]
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it : mp) {
            if(flip) {
                //it.second ko reverse kardo
                reverse(it.second.begin(), it.second.end());
            }

            for(int &num : it.second) {
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};



//**************************Aproach-------2********************

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      int m=mat.size();
      int n=mat[0].size();
      int row=0;
      int col=0;
      bool up=true;
      //The above are some intilisations;
      vector<int>result;
      while(row<m and col<n){
          if(up==true){
              //when we are moving in the up direction
              while(row>0 and col<n-1){
               result.push_back(mat[row][col]);
               row--;
               col++;
              }
              result.push_back(mat[row][col]);
              if(col==n-1){
                  row++;
              }
              else{
                  col++;
              }
          }
         else{
             //when we are moving in the down direction
             while(col>0 and row<m-1){
                 result.push_back(mat[row][col]);
                 row++;
                 col--;
             }
             result.push_back(mat[row][col]);
             if(row==m-1){
                 col++;
             }
             else{
                 row++;
             }
         }
         up=!up; //reversing the condition to move in alternate direction
      }
    return result;
    }
};
