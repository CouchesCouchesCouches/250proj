#include "globals.h"
#include "populate.h"
#include "yen.h"

using namespace YEN;

void populate() {
    cout << "populate.cc:\nAdding edges to qDGraph using populate()\n";
    qDGraph.addEdge(0, 1, 4);
    qDGraph.addEdge(0, 7, 8);
    qDGraph.addEdge(1, 2, 8);
    qDGraph.addEdge(1, 7, 11);
    qDGraph.addEdge(2, 3, 7);
    qDGraph.addEdge(2, 8, 2);
    qDGraph.addEdge(2, 5, 4);
    qDGraph.addEdge(3, 4, 9);
    qDGraph.addEdge(3, 5, 14);
    qDGraph.addEdge(4, 5, 10);
    qDGraph.addEdge(5, 6, 2);
    qDGraph.addEdge(6, 7, 1);
    qDGraph.addEdge(6, 8, 6);
    qDGraph.addEdge(7, 8, 7);
}
