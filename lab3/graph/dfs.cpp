#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

vector<int> dfs(vector<int>adjList[] , int src , vector<int> & visited)
{
   
    visited[src] = 1;
    ans.push_back(src);
    for(auto neig : adjList[src])
    {
        if(!visited[neig])
            dfs(adjList , neig , visited);
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
   vector<int> visited(V,0);
   vector<int> ans = dfs(adjList , 0, visited);
   cout<< " dfs traversal of the graph = "; 
   for(auto it : ans)
   {
       cout << it << " ";
   }
   return 0;
} 