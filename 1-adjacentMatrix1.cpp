// Adjacent Matrix is a way of representing graphs in a computer


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool adjMatrix[6][6];

void addEdge(int u,int v)
{
    adjMatrix[u][v]=true;
    adjMatrix[v][u]=true;
}
void printMat()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
   int t;
   cin>>t;
   while(t--)
   {
     for(int i=0;i<6;i++)
     {
         int u,v;
         cin>>u>>v;
         addEdge(u,v);
     }
   }
    return 0;
}
