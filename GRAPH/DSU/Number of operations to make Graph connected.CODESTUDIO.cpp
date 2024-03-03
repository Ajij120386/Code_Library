#include<bits/stdc++.h>

const int N=1e5+7;
int parent[N];
int Size[N];
int Rank[N];

void makeSet(int n){
    for (int i = 1; i <=n; i++){
    parent[i] = i;
     Size[i]=1;
     Rank[i]=0;
   }
}


int FindPar(int u){

    if (u == parent[u])
           return u;
//path compression
    return parent[u] = FindPar(parent[u]);
}

void Union(int u, int v)
{

    u = FindPar(u);
    v = FindPar(v);

    /*
    //union By Rank

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
    */
//union by size
    if(u!=v){

        if(Size[u]<Size[v])  swap(u,v);
         parent[v]=u;
         Size[u]+=Size[v];
    }
}



int makeGraphConnected(int n, vector < pair < int,int > > edges, int m)
{
	makeSet(n);

    for(int i=0;i<m;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
      Union(u,v);

    }
   int connected_com=0;
    int cnt=0;
//joto gola root ase toto golai to connected component hobe

for(int i=1;i<=n;i++){

    if(FindPar(i)==i){

        connected_com++;
        if(Size[i]==2) cnt++;
}

}
if(connected_com==cnt){
   return -1;
}
return connected_com-1;

}
