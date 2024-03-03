#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

vector<int> topKFrequent(vector<int>& nums, int k) {
        //for min heap;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >heap;
  priority_queue<pi, vector<pi>, greater<pi> > heap;
        vector<int>ans;
        unordered_map<int,int>mp;
       for(auto it: nums) mp[it]++;
      for(auto it: mp) {
          heap.push({it.second,it.first});
          if(heap.size()>k) heap.pop();
      }
      while(!heap.empty()){
          auto it=heap.top();
       ans.push_back(it.second);
       heap.pop();
      }
      return ans;
    }


