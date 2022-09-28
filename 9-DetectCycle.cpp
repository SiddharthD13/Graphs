#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


bool isCyclicConnected(vector<int> adj[],int s,int n,vector<bool> &visited)
{
    vector<int> parent(n,-1);
    queue<int>q;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
                parent[v] = u;
            }
            else if(parent[u]!=v)
                return true;
        }
    }
    return false;
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

    bool flag= false;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && isCyclicConnected(adj,i,n,visited))
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;   
}