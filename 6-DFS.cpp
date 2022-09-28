#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "adjacent nodes of node " << i << " is \n";
        for (auto ele : adj[i])
        {
            cout << "-> " << ele << endl;
        }
    }
}

void DFSRecur(vector<int> adj[], vector<bool> &visited, int u)
{
    visited[u]=true;
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++) // for all the adjacent elements present in that particular index
    {
        if(visited[adj[u][i]]==false)
            DFSRecur(adj,visited,adj[u][i]);
    }
}

void DFS(vector<int> adj[], int n)
{
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            DFSRecur(adj,visited,i);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    //printList(adj, n);
    DFS(adj,n);
    return 0;
}