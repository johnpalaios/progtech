#include <iostream>
#include <vector>
using namespace std;

class Graph {
 private:
 int V; //number of vertices
 vector<int> *adj; // Pointer to an array containing adjacency lists
 bool iscyclic(int v,bool visited[],bool *rs,vector<int>&path);

 public:
 Graph(int V);
 ~Graph() {delete[] adj;}
 void addEdge(int u, int v);
 bool cycle(vector<int> path);
 };

 Graph::Graph(int V) //CONSTRUCTOR
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s vector.
}

