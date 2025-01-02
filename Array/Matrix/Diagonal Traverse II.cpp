

/*


Input: nums =  [1,2,3,4,5]
               [6,7]
               [8]
               [9,10,11]
               [12,13,14,15,16]

Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

      map<int, vector<int>> mp;

        vector<int> result;

        //fill the map using [i+j]
        for(int i = 0; i<mat.size(); i++) {
            for(int j = 0; j<mat[i].size(); j++) {   // Use nums[i].size() instead of nums[0].size()
                mp[i+j].push_back(mat[i][j]);
            }
        }


        for(auto &it : mp) {

                //it.second ko reverse kardo
                reverse(it.second.begin(), it.second.end());


            for(int &num : it.second) {
                result.push_back(num);
            }


        }

        return result;
    }
};
