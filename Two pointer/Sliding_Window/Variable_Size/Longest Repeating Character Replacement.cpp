
    /*
       A lot of people seem to have doubts as to why we aren't updating maxi
       when we are reducing window length. Here's the reason:
     Our aim here : Maximize the length of window (j-i+1)

What would happen if we don't decrease the value of maxi upon deleting an
element at left of window? Could we possible get a false "satisfaction of the criteria"? :YES!

But will it be a problem? No, since the new length that would satisfy
 would still be lesser than a previous "correct" length that we've updated as "ans".

Then, clearly that isn't a problem, but lastly we need to check whether this could
pose a problem to us setting sliding windows and potentially miss the largest length.
 This too isn't going to be a problem, since upon fulfilment of the criteria we aren't
 changing the pointer length, we've just continued to maintain this decreased length,
 as and when the right pointer increases in it's routine manner, that would accurately
 check for new lengths (since maxi would need to increase to receive a better final ans,
                                                                                                                                                                                                                                                                                                                                                                                                                                                                 and there is a proper check that has been placed for incrementing maxi)
*/
    class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, maxi = 0;
        unordered_map<char,int>mp;
        int ans = -1;
        while(j < n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);

            if((j-i+1) - maxi > k){

                    //we need not decrease max frequecny, bcz we have already longest substring why we srink them,,
                    // so we go forward looking for next better
                mp[s[i]]--;
                i++;
            }
           if((j-i+1) - maxi <= k )
           {
            ans = max(ans, (j-i+1));
            j++;
           }
        }
        return ans;
    }
};
