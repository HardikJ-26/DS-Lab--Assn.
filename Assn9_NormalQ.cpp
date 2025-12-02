//Q1 BFS IN GRAPHS
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>bfsofGraph(int v,vector<int>adj[]) //here v is total possible elements
{
    int vis[v]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {   
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>&ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    vector <int> adj[5];
    
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);

    vector <int> ans = bfsofGraph(5, adj);
    printAns(ans);
    return 0;
}
//TC-O(N)/SC-O(N)
*/

//Q2 DFS IN GRAPHS
/*
#include <bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int>adj[],vector<int>&visited,vector<int>&result) //here v is the element being checked
{
    visited[v]=1;
    result.push_back(v);
    for(int i : adj[v])
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,result); //can also use a stack
        }
    }
}
int main()
{
    int V=5;
    vector<int>adj[V];
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};

    vector<int> visited(V, 0);
    vector<int> result;
    dfs(0, adj, visited, result);

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
//TC-O(N)/SC-O(N)
*/

//Q3 MINIMUM SPANNING TREE
/*
#include <bits/stdc++.h>
using namespace std;

int spanningtree(int v,vector<vector<int>>adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node]==1)
        continue;
        else
        {
            sum+=dis;
            vis[node]=1;
            for(auto it : adj[node])
            {       
                int adjnode=it[0];
                int adjdist=it[1];
                if(!vis[adjnode])
                pq.push({adjdist,adjnode});
            }
        }
    }
    return sum;
}
int main()
{
    int v=6;
    vector<vector<int>>edges={{0,1,2},{0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>>adj[v];
    for (auto it : edges) 
    {
    vector<int> tmp(2);
    //connecting u->v
    tmp[0] = it[1]; //neighbour node
    tmp[1] = it[2]; //weight
    adj[it[0]].push_back(tmp);
    //connecting v->u
    tmp[0] = it[0];
    tmp[1] = it[2];
    adj[it[1]].push_back(tmp);
    }
	int sum = spanningtree(v, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}
//TC-O(NLOGN)/SC-O(N)
*/

//Q4 DJIKSTRAS ALGO
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>djikstra(int v,vector<vector<int>>adj[],int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v);
    for(int i=0;i<v;i++)
    {
        dist[i]=1e9;
    }
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it : adj[node])
        {
            int edgeweight=it[1];
            int adjnode=it[0];
            if(dis+edgeweight<dist[adjnode])
            {
                dist[adjnode]=dis+edgeweight;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}
int main()
{
    int V = 3, E = 3, S = 2; //S is source vertex
    vector<vector<int>> adj[V];

    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res=djikstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}
//TC-O(NLOGN)/SC-O(N)
    */