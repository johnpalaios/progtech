// A C++ Program to detect cycle in a graph
// A C++ Program to detect cycle in a graph
#include<bits/stdc++.h>
#include <algorithm>    // std::reverse
using namespace std;

class Graph
{
    int V;    // No. of vertices
    vector<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
    public:
    Graph(int V);   // Constructor
     ~Graph() { delete[] adj;}
    void addEdge(int v, int w);   // to add an edge to graph
    bool cycle(vector<int> &path) ;    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s vector.
}

// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
vector<int> path;
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                { //path.push_back(v);
                return true;}
            else if (recStack[*i])
                {
                   //path.push_back(v);
                   return true;
                }
        }

    }
     //if(!path.empty()) path.pop_back();
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
//vector<int> path;
bool Graph::cycle(vector<int> &path)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            {
                for(int i = 0; i < V; i++)
                {if(recStack[i]) path.push_back(i);}
            //std::reverse(path.begin(),path.end());
            return true;
            }


    return false;
}
/*int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 6);
    g.addEdge(1, 5);
    g.addEdge(5, 6);

    /*Graph l(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(0, 3);

    /*Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    vector<int> path;
    vector<int> stac;


    if(g.cycle(path))
        {
         cout << "CYCLE:";
         for(int i=0;i<path.size();i++)
         {cout << " " << path[i];}
         cout << endl << "This is what came out of the stack :" ;
         for(int i=0;i<stac.size();i++)
         {cout <<" "<< stac[i];}
         cout << endl;
        }
    else
        cout << "NO CYCLE" << endl;
    return 0;
 /*
 int V, E;
 cin >> V >> E;
 Graph g(V);
 for (int i = 0; i < E; ++i) { int u, v; cin >> u >> v; g.addEdge(u, v); }
 vector<int> path;
 bool c = g.cycle(path);
 if (c) {
 cout << ”CYCLE: ”;
 for (int i = 0; i < path.size(); ++i)
 cout << path[i] << (i == path.size()-1 ? ”\n” : ” ”);
 } else {
 cout << ”NO CYCLE” << endl;
 }
 }*/

