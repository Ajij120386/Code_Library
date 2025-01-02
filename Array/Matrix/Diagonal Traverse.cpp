

/*
     Input: mat = [
                         [1,2,3]
                         [4,5,6]
                         [7,8,9]
                 ]

       Output: [1,2,4,7,5,3,6,8,9]
*/
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
