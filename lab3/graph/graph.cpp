// bfs (breath first search)

#include<bits/stdc++.h>
using namespace std;


void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

vector<int> bfs(vector<int>adjList[] , int V)
{
    vector<bool> visited;
    visited.resize(4,false);
    
    vector<int>ans;
    
    queue<int>q;
    q.push(0);
    visited[0]=true;
    
    while(!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        
        for(auto v : adjList[node])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }
    return ans;
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

    int V = 4 ;

    vector<int>adjList[V];

    addEdges(adjList , 0 , 1);
    addEdges(adjList , 0 , 3);
    addEdges(adjList , 1 , 3);
    addEdges(adjList , 1 , 2);
    addEdges(adjList , 2 , 3);
   
   printGraph(adjList , V);


   cout<<endl;
   
   vector<int> ans = bfs(adjList , V);
   cout<< " bfs traversal of the graph = "; 
   for(auto it : ans)
   {
       cout << it << " ";
   }
   return 0;
} 