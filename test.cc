#include "yen.h"
//#include "my_class.h"
using namespace YEN;

int main() 
{ 
    // create the graph 
    int V = 35; 
    Graph g(V); 
    // the picture of g is in the link of line 3
    // edge between u, v. The third int is weight
    g.addEdge(0, 10, 20);
    g.addEdge(0, 11, 20);
    g.addEdge(1, 13, 20);
    g.addEdge(2, 24, 20);
    g.addEdge(2, 25, 20);
    g.addEdge(3, 10, 20);
    g.addEdge(3, 12, 20);
    g.addEdge(3, 16, 20);
    g.addEdge(3, 14, 20);
    g.addEdge(3, 15, 20);
    g.addEdge(4, 11, 20);
    g.addEdge(4, 12, 20);
    g.addEdge(4, 17, 20);
    g.addEdge(4, 18, 20);
    g.addEdge(5, 13, 20);
    g.addEdge(5, 14, 20);
    g.addEdge(5, 20, 20);
    g.addEdge(5, 26, 20);
    g.addEdge(6, 24, 20);
    g.addEdge(6, 20, 20);
    g.addEdge(6, 23, 20);
    g.addEdge(6, 21, 20);
    g.addEdge(6, 27, 20);
    g.addEdge(7, 25, 20);
    g.addEdge(7, 23, 20);
    g.addEdge(7, 22, 20);
    g.addEdge(7, 32, 20);
    g.addEdge(8, 15, 20);
    g.addEdge(8, 26, 20);
    g.addEdge(8, 27, 20);
    g.addEdge(8, 28, 20);
    g.addEdge(8, 29, 20);
    g.addEdge(9, 18, 20);
    g.addEdge(9, 32, 20);
    g.addEdge(9, 30, 20);
    g.addEdge(9, 31, 20);
    g.addEdge(10, 0, 20);
    g.addEdge(10, 3, 20);
    g.addEdge(11, 0, 20);
    g.addEdge(11, 4, 20);
    g.addEdge(12, 3, 20);
    g.addEdge(12, 4, 20);
    g.addEdge(13, 1, 20);
    g.addEdge(13, 5, 20);
    g.addEdge(14, 5, 20);
    g.addEdge(14, 3, 20);
    g.addEdge(15, 3, 20);
    g.addEdge(15, 8, 20);
    g.addEdge(16, 3, 20);
    g.addEdge(16, 33, 20);
    g.addEdge(17, 4, 20);
    g.addEdge(17, 33, 20);
    g.addEdge(18, 4, 20);
    g.addEdge(18, 9, 20);
    g.addEdge(19, 33, 20);
    g.addEdge(19, 34, 20);
    g.addEdge(20, 5, 20);
    g.addEdge(20, 6, 20);
    g.addEdge(21, 6, 20);
    g.addEdge(21, 34, 20);
    g.addEdge(22, 7, 20);
    g.addEdge(22, 34, 20);
    g.addEdge(23, 6, 20);
    g.addEdge(23, 7, 20);
    g.addEdge(24, 2, 20);
    g.addEdge(24, 6, 20);
    g.addEdge(25, 2, 20);
    g.addEdge(25, 7, 20);
    g.addEdge(26, 5, 20);
    g.addEdge(26, 8, 20);
    g.addEdge(27, 6, 20);
    g.addEdge(27, 8, 20);
    g.addEdge(28, 8, 20);
    g.addEdge(28, 33, 20);
    g.addEdge(29, 8, 20);
    g.addEdge(29, 34, 20);
    g.addEdge(30, 9, 20);
    g.addEdge(30, 33, 20);
    g.addEdge(31, 9, 20);
    g.addEdge(31, 34, 20);
    g.addEdge(32, 7, 20);
    g.addEdge(32, 9, 20);
    g.addEdge(33, 16, 20);
    g.addEdge(33, 17, 20);
    g.addEdge(33, 19, 20);
    g.addEdge(33, 28, 20);
    g.addEdge(33, 30, 20);
    g.addEdge(34, 21, 20);
    g.addEdge(34, 22, 20);
    g.addEdge(34, 19, 20);
    g.addEdge(34, 29, 20);
    g.addEdge(34, 31, 20);
  
    /*vector<int> path = g.dijkstra(0, 4); 
    showlist(path);
    cout << "\n";
    int cost = g.dist[4];
    cout << cost << endl;
    */
    vector<vector<int> > A;
    // shortest path from node 0 to 4, K = 8
    A = yen(g, 0, 2, 15);
    for(auto it = A.begin(); it != A.end(); ++it) {
        showlist(*it); 
        cout << "\n";
    }
    return 0; 
} 
