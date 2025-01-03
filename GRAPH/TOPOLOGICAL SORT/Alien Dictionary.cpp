//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:


   vector<int>topoSort(int n, vector<int>adj[] )
   {
        vector<int>indegree(n,0);
         for(int i=0;i<n;i++)
         {
            for(auto it: adj[i])
             indegree[it]++;
         }
         queue<int>q;

         for(int i=0;i<n;i++)
         {
            if(indegree[i]==0) q.push(i);
         }

         vector<int>topo;

    while(!q.empty())
    {

        int node=q.front();
        topo.push_back(node);
        q.pop();

        for(auto it: adj[node])
        {

           indegree[it]--;

           if(indegree[it]==0) q.push(it);

        }
    }

    return topo;

   }



    string findOrder(string dict[], int N, int K) {
        //code here





         vector<int>adj[K];

          for(int i=0;i<N-1;i++)
          {
            string one=dict[i];
            string two=dict[i+1];

            int sz=min(one.size(),two.size());
            for(int j=0;j<sz;j++)
            {
                if(one[j]!=two[j])
                {
                    adj[one[j]-'a'].push_back(two[j]-'a');
                    break;
                }


            }


          }


      vector<int>ans= topoSort(K, adj );


      string res=" ";

         for(auto it : ans)
         res= res+ char(it +'a');




            return res;

    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
