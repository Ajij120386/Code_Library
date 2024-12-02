
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
