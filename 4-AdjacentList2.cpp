#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


    void addEdge(vector<int> adj[],int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printList(vector<int> adj[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"adjacent nodes of node "<<i<<" is \n";
            for(auto ele:adj[i])
            {
                cout<<"-> "<<ele<<endl;
            }
        }
    }

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    printList(adj,n);
}