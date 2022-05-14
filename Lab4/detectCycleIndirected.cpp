#include<bits/stdc++.h>
using namespace std;

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

// find cycle directed graph 
void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
}

int iscyclebfs(vector<int>adjList[] , int V )
{
    queue<int>q;
    vector<int> storeIndegree(V , 0);
    int countVer = 0;

    //  task1 : find  indegree of all nodes 
    for(int v = 0 ; v < V ; v++)
    {
        for(auto neig : adjList[v])
            storeIndegree[neig]++;
    }

    // task 2 : find the vertex having zero incoming node.

    for(int v = 0 ; v < V ; v++)
    {
        if(storeIndegree[v] == 0)
            q.push(v);
    }

    // task 3 : implement bfs
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        countVer++;

        for(auto neig : adjList[node])
        {
            storeIndegree[neig]--;
            if(storeIndegree[neig] == 0)
                q.push(neig);
        }

    }

    if(countVer == V)
        return 0;
    else
        return 1;    
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
   
         
   
  int  flag = iscyclebfs(adjList ,V );
   
  if(flag)
        cout<<"Cycle is  present ...";
  else
        cout<<"Cycle is not  present ....";     
   
   return 0;
} 