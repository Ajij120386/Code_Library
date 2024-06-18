
//1st



    // Time complexity: O(N log N + K log N) = O(N log N)
    //Space complexity: O(N + N) = O(N),
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
       vector<pair<int, int>> projects;

        // Creating vector of pairs (capital, profits)
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sorting projects by capital required
        sort(projects.begin(), projects.end());

        // Max-heap to store profits, using greater to create a max-heap
     priority_queue<int> maxHeap;
        int i = 0;

        // Main loop to select up to k projects
        for (int j = 0; j < k; ++j) {
            // Add all profitable projects that we can afford
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // If no projects can be funded, break out of the loop
            if (maxHeap.empty()) {
                break;
            }

            // Otherwise, take the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};




//2nd   Using Two heap



class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        priority_queue<pair<int,int>>mxh;
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>mnh;

        for(int i=0;i<capital.size();++i)
            mnh.push({capital[i], profits[i]});

        while(k > 0)
        {
           while(!mnh.empty() && mnh.top().first<=w)
           {
               auto p = mnh.top();
               mnh.pop();
               mxh.push({p.second, p.first});
           }
           if(!mxh.empty())
           {
               w += mxh.top().first;
               mxh.pop();
               k--;
           }
           else break;
        }

        return w;

    }
};



//Using Binary search
class Solution {
public:
    using int2 = pair<int, int>;

    static int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        const int n= profits.size();
        vector<int2> cp(n);

        for (int i = 0; i < n; i++)
            cp[i] = {capital[i], profits[i]};

        sort(cp.begin(), cp.end());

        priority_queue<int> pq;

        int curr=0;
        for (int i = 0; i<k; i++) {
        //    cout<<idx<<":"<<w<<endl;
            for ( ; curr<n && cp[curr].first<=w; curr++)
                pq.push(cp[curr].second);

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else break;
        }
        return w;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
