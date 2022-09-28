#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Graph
{
    bool **adjMat;
    int nodes;
    public:
    Graph(int nodes)
    {
        this->nodes=nodes;
        adjMat=new bool*[nodes]; // initialisation of rows
        for(int i=0;i<nodes;i++)
        {
            adjMat[i]=new bool[nodes]; // for each element a new array is created thus crerating a 2-d array
            for(int j=0;j<nodes;j++)
            {
                adjMat[i][j]=false;
            }
        }
    }
    void addEdge(int u, int v)
    {
        adjMat[u][v] = true;
        adjMat[v][u] = true;
    }

    void printMat()
    {
        for(int i=0;i<nodes;i++)
        {
            cout<<i<<": ";
            for(int j=0;j<nodes;j++)
            {
                cout<<adjMat[i][j]<<" ";
                
            }
            cout<<endl;
        }
    }
};

int main() {
   int t;
   cin>>t;
   while(t--)
   {
       int n,e; //n is vertice and e is the edge
       cin>>n>>e; 
       Graph graph(n);
     for(int i=0;i<n;i++)
     {
         int u,v;
         cin>>u>>v;
         graph.addEdge(u,v);
     }
     graph.printMat();

   }
    return 0;
}
