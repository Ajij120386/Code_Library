
//APPROACH_I  TC: O(32*n) SC:O(1)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
         vector<int>f(32,0);
        for(auto u:nums){
             for(int i=0;i<32;i++)
                if(u&(1<<i)) f[i]++;

            }
        int res=0;
        for(int i=0;i<32;i++){
            if(f[i]%3) res+=(1<<i);
            }
        return res;
    }
};


//APPROACH_II  TC: O(32*n) SC:O(1)




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
         vector<int>f(32,0);
        for(auto u:nums){
             for(int i=0;i<32;i++)
                if(u&(1<<i)) f[i]++;

            }
        int res=0;
        for(int i=0;i<32;i++){
            if(f[i]%3) res+=(1<<i);
            }
        return res;
    }
};





//optimal APPROACH_III  TC: O(n) SC:O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};
