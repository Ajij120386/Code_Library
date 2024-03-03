#include<bits/stdc++.h>

#define MX 1000000
int parent[MX];
int Rank[MX];
void makeSet(int n){
    for (int i = 1;i<=n; i++){
    parent[i] = i;
    Rank[i]= 0;
   }
}


int FindPar(int u){

    if (u == parent[u])
           return u;

    return parent[u] = FindPar(parent[u]);
}

void Union(int u, int v)
{

    u = FindPar(u);
    v = FindPar(v);

       if(Rank[u] < Rank[v])
        {
        parent[u] = v;
       }
    else if(Rank[v] < Rank[u])
        {
        parent[v] = u;
         }
    else
    {
        parent[v] = u;
        Rank[u]++;
    }
}


int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
	vector<pair<int, pair<int,int> > >edges;
    for(int i=0;i<m;i++)
    {
        int u=connections[i][0];
         int v=connections[i][1];
          int wt=connections[i][2];

        edges.push_back({ wt, {u,v}});

    }


    sort(edges.begin(),edges.end());

    makeSet(n);

    int total_cost=0;



    for(auto it: edges)
  {

        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;

        if(FindPar(u)!=FindPar(v))
        {

            Union(u,v);
            total_cost+=wt;

        }

  }
  unordered_set<int>st;   //checking all city are connectected or not
for(int i = 1;i<=n;i++){
    st.insert(FindPar(i));
   }
  if(st.size()>1)
       return -1;

    return total_cost ;



   }

