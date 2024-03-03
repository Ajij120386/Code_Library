#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long

vector<int> adj[sz];
int vis[sz], level[sz];

void bfs(int node, int lev)
{
    vis[node] = 1;
    queue< pair<int,int  > > q;

    q.push({node,lev});

    while (!q.empty())
    {
         int node = q.front().first;
         int step=  q.front().second;

        ///for all a,b,c summation of distance is calculated
         level[node] += step;

         q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, step + 1});
                vis[it] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t, i, n, m, a, b, c, ans;
    t = 1;
    while (t--)
    {
        cin >> n >> m;
        while (m--)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cin >> a >> b >> c;
        for (i = 0; i < 3; i++)
        {
            memset(vis, 0, sizeof(vis));

            if (i == 0)
            {
                bfs(a, 0);

             /*
                for (int j = 1; j <= n; j++)
              {
                cout<<level[j]<<endl;

                }
              cout<<endl;
              cout<<endl;

              */
            }

            else if (i == 1)
           {

                bfs(b, 0);


             /*
                for (int j = 1; j <= n; j++)
              {
                cout<<level[j]<<endl;

                }
              cout<<endl;
              cout<<endl;

              */
            }

            else{

                 bfs(c, 0);

             /*
                for (int j = 1; j <= n; j++)
              {
                cout<<level[j]<<endl;

                }
              cout<<endl;
              cout<<endl;

              */
            }

        }

        ans = level[1];
        a = 1;
        //among all this level find minimum one
        for (i = 2; i <= n; i++)
        {
            if (level[i] < ans)
            {
                ans = level[i];
                a = i;
            }
        }
        cout << a << "\n";
    }

    return 0;
}
