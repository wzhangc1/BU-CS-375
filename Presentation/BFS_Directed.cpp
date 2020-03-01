// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices  
// reachable from s. 
#include <fstream>
#include <iostream>
#include <list> 
#include <string>
#include <cstdio>
#include <ctime>

using namespace std; 
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<int> *adj;   
    void DFSUtil(int v, bool visited[]); 
 
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   
    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 1; i <= V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front();
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
  
  void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true;
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
// Driver program to test methods of graph class 
int main(int argc, char *argv[])
{
	ifstream fin;
	int n;
    int m;
    
	fin.open(argv[1]);
    
    fin >> n >> m;
    
    Graph g(n+1); 
    
    while (fin)
    {
		fin >> n >> m;
		g.addEdge(n, m);
	}
  
    clock_t start;
    double duration;
         start = clock();
    g.BFS(1); 
  duration = 1000 * ( clock() - start ) / (double) CLOCKS_PER_SEC;
  cout<< duration <<'\n';
  
     start = clock();
    g.DFS(1); 
  duration = 1000 * ( clock() - start ) / (double) CLOCKS_PER_SEC;
  cout<< duration <<'\n';
  
  fin.clear();
fin.seekg(0, ios::beg);

fin >> n >> m;

while (fin)
    {
		fin >> n >> m;
		g.addEdge(m, n);
	}
	        start = clock();
    g.BFS(1); 
  duration = 1000 * ( clock() - start ) / (double) CLOCKS_PER_SEC;
  cout<< duration <<'\n';
  
     start = clock();
    g.DFS(1); 
  duration = 1000 * ( clock() - start ) / (double) CLOCKS_PER_SEC;
  cout<< duration <<'\n';
  fin.close();
	 
    return 0; 
   
} 
