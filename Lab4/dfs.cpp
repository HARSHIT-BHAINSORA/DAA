#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void dfs(vector<int>adjList[] , int src , vector<int> & visited , vector<int>&ans)
{
   
    visited[src] = 1;
    ans.push_back(src);
    for(auto neig : adjList[src])
    {
        if(!visited[neig])
            dfs(adjList , neig , visited, ans);
    }
}

vector<int> dfsTraversal(vector<int> adjList[] , int V)\
{
    vector<int>ans;
    vector<int> visited(V,0);
    for(int i = 0 ; i < V ; i++)
    {
        if(!visited[i])
            dfs(adjList , i , visited , ans);
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


   cout<<endl;
   vector<int> ans = dfsTraversal(adjList , V);
   cout<< " dfs traversal of the graph = "; 
   for(auto it : ans)
   {
       cout << it << " ";
   }
   return 0;
} 
