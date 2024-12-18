
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {



        queue<pair<string, int>> q;

        string replace="ACGT";


        q.push({startGene, 1});


        unordered_set<string> st(bank.begin(), bank.end());

        st.erase(startGene);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();



            for (int i = 0; i < word.size(); i++)
            {

                char original = word[i];
                for (int j=0; j< replace.size(); j++)
                {
                    word[i] = replace[j];
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                         if (word == endGene)
                                 return steps;
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return -1;




    }
};
