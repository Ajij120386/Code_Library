
/*********Approach----1******************
class Solution {
public:

 int n;
 vector<vector<int>>result;

    void backtrack(vector<int>& nums, int ind, vector<int>& curr) {

        if(curr.size() > 1)
            result.push_back(curr);
        
        unordered_set<int> st;
        for(int i = ind; i<n; i++) {
            if((curr.empty() || nums[i]  >= curr.back()) && st.find(nums[i]) == st.end()) {
                
                curr.push_back(nums[i]);
                backtrack(nums, i+1, curr);
                curr.pop_back();
                
                st.insert(nums[i]); //eta exlude include kora ssesh 
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        n = nums.size();
       
    
        
        vector<int> curr;
        
        backtrack(nums, 0, curr);
        
        return result;
    }

};

//*********Approach----2******************




class Solution {
public:


   void func( int idx , vector<int>&nums, vector<int>&curr, set<vector<int>>&ans){

        int n=nums.size();

        //If we have our index greater than or equal to sizeof nums then we cant go further
        //so we will check if there is a subarray with size greater than equal to 2
        if(idx>=n){

            if(curr.size()>=2){

                //if we have such subarray we will insert it to the set
                ans.insert(curr);
            }
            return ;
        }
        //now for [0,n-1] index we will check either condition for inserting into a vector
            //1. if a vector is empty so we can push the element easily
            //2. if a last element is less than equal to cur element
        if(curr.empty()||nums[idx]>=curr.back()){

            //we will push back into a vector and then call the func for idx+1;
            curr.push_back(nums[idx]);
            func(idx+1,nums,curr,ans);
            //we are removing element because a vector is being passed by reference
            curr.pop_back();
        }
        //calling the function without that value
        func(idx+1,nums,curr,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        vector<int>temp;

        set<vector<int>>ans;

        func(0,nums,temp,ans);
        //typecasting the set into vector and returning it we can do it manually also
          return vector(ans.begin(),ans.end());

    }







};
