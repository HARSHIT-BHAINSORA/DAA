// bfs (breath first search)

#include<bits/stdc++.h>
using namespace std;


void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

bool bfs(vector<int>adjList[]  , int node, int V , int dest)
{
    vector<bool> visited(V ,false);
    
    vector<int>ans;
    
    queue<int>q;
    q.push(node);
    visited[node]=true;

    
    
    while(!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        
        if(node == dest)
            return true;
        
        for(auto v : adjList[node])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }
    return false;
}

void printGraph(vector<int> adjList[] , int V)
{
    for(int v = 0 ; v < V ; v++)
    {
        cout<<"The node is = " << v <<endl;
        cout<<"The neighbour are = ";
        for(auto it : adjList[v])
        {
            cout<< it << " ";
        }
        cout<<endl;
    }
}

int main(){

    int V ,E;

    cout<<"Enter the number of vertices = ";
    cin>>V;

    cout<<"Enter the number of Edges = ";
    cin >> E;

    vector<int>adjList[V];

    int src , dest ;
    for(int e = 0 ; e < E ; e++)
    {
        cin>>src;
        cin>>dest;
        addEdges(adjList , src ,dest);
    }
   
   printGraph(adjList , V);

    int source , destination;
    cout<< "Enter the source : ";
    cin>>source;
    
    cout<<"Enter the destination : ";
    cin >> destination;
   cout<<endl;
   bool flag= bfs(adjList ,source , V , destination);
   
   if(flag)
        cout<<"The path is present ...";
   else
        cout<<"No path exist ....";     
   
   return 0;
} 