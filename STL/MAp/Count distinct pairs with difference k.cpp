
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
		map<int,int>mp;
		for(int i = 0; i < nums.size(); i++){
			mp[nums[i]]++;
		}
		int cnt = 0;
		// difference equal to zero
		if(k == 0){
			for(auto i: mp){
				// frequency of element is greater than one then distinct pair is possible
				if(i.second > 1)
					cnt++;
			}
		}
		// difference is not equla to zero
		else{
			for(auto i: mp){
				// frequency of element + k is not zero then distinct pair is possible
				if(mp.find(i.first + k) != mp.end()){
					cnt++;
				}
			}
		}
		return cnt;
	}

};
