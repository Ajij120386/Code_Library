
class Solution {
public:
    string customSortString(string order, string str) {

        vector<int> index(26, INT_MAX);

        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;


        auto lambda = [&](char &ch1, char &ch2) {

            // "The characters which don't occur in "str" must be sorted as per English Alphabet order".

            if(index[ch1-'a'] == index[ch2-'a'])
                return ch1 < ch2;

            return index[ch1-'a'] < index[ch2-'a'];
        };

        sort(begin(str), end(str), lambda);
        return str;

    }
};
