#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Graph
{
    int V;
    list<int>* adj;
    public:
        Graph(int v)
        {
            this->V=v;
            adj=new list<int>[v];
        }

        void addedge(int u,int v);
        void printlist(int nodes);
        
        void BFS(int v);
};

void Graph::addedge(int u,int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::printlist(int n)
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

void Graph::BFS(int v)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    list<int> qu;
    visited[v]=true;
    qu.push_back(v);

    while(!qu.empty())
    {
        v=qu.front();
        cout<<v<<" ";
        qu.pop_front();
        for(auto ele:adj[v])
        {
            if(!visited[ele]) //if it is not visited
            {
                visited[ele]=true;
                qu.push_back(ele);
            }
        }

    }
}

int main()
{
    int nodes;
    int edges;
    cin>>nodes>>edges;
    Graph graph(nodes);
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph.addedge(u,v);
    }

    graph.BFS(50);
    return 0;
}

/*
    7 7
    0 1
    0 2
    2 3
    1 4
    1 6
    2 5
    5 6
*/