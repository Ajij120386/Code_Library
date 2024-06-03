typedef pair<int,int> pi;

class myComp{
public:

    int operator() (pi &a, pi &b)
    {
        // freq same then return greater number
        if (a.first == b.first)
                return a.second < b.second;

        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        // using max heap and hashmap
        int n = nums.size();
        vector<int> ans;
        map<int,int> mpp;
        priority_queue<pi, vector<pi>, myComp> pq;

        for(auto it : nums){
            mpp[it]++;
        }
        for(auto val : mpp){
            pq.push({val.second, val.first});
        }

        while(!pq.empty()){

            int freq = pq.top().first;
            for(int j = 0; j <freq; j++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};
