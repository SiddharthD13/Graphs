/* TO Find the no of disconnected graphs and also to check 
whether the graph is disconnected or not 
*/



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
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            DFSRecur(adj,visited,i);
            count++;
            cout<<endl;
        }
    }
    cout<<"The number of connected components = "<<count<<endl;
    if(count>1)
        cout<<"Disconnected Graph \n";
    else 
        cout<<"Connected Graph \n";
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    //printList(adj, n);
    DFS(adj,n);
    return 0;
}


//TEST CASE
// 8 5
// 0 1
// 1 2
// 4 5
// 5 6
// 3 7