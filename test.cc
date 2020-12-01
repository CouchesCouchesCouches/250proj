#include "yen.h"
//#include "my_class.h"
using namespace YEN;

int main() 
{ 
    // create the graph 
    int V = 9; 
    Graph g(V); 
    // the picture of g is in the link of line 3
    // edge between u, v. The third int is weight
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    /*vector<int> path = g.dijkstra(0, 4); 
    showlist(path);
    cout << "\n";
    int cost = g.dist[4];
    cout << cost << endl;
    */
    vector<vector<int> > A;
    // shortest path from node 0 to 4, K = 8
    A = yen(g, 0, 4, 8);
    for(auto it = A.begin(); it != A.end(); ++it) {
        showlist(*it); 
        cout << "\n";
    }
    return 0; 
} 
