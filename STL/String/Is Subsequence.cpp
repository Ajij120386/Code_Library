
/*************************************************** C++ *************************************************/
//Follow Up Approach
//Approach-1 (Using Binary Search) -> This is an important concept for qns like Leetcode-792
class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, vector<int>> mp;

        //saving incides of each character in t
        for(int i = 0; i<t.length(); i++) {
            char ch = t[i];
            mp[ch].push_back(i);
        }

        int prev = -1;
        //Now, look if we can find characters of s with increasing indices
        //Example : s = "abc", t = "ahbgdc" -> {a -> {0}, h -> {1}, b ->{2}, g -> {3}, d -> {4}, c -> {5}
        //Characters of "abc"
        //a -> {0}
        //b -> {2}
        //c -> {5}
        //indices are in increasing order -> {0, 2, 5}, so this is a subsequence of t
        for(char &ch : s) {
            if(mp.find(ch) == mp.end())
                return false;

            vector<int> indices = mp[ch];

        auto it = upper_bound(indices.begin(), indices.end(), prev);


            if(it == indices.end())
                return false;

            prev = *it;
        }

        return true;
    }
};

//Approach-2 (Simplest O(n) approach)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m  = t.length();
        int n  = s.length();
        int i = 0, j = 0;

        while(i < m) {
            if(t[i] == s[j])
                j++;
            i++;
        }

        return j == n;
    }
};

