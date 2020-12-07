#include "populate.h"
#include "yen.h"
#include "globals.h"

using namespace YEN;

int main() 
{ 
    cout << "use_globals.cc:\ncalling populate() from populate.cc\n";
    populate();
    vector<vector<int> > A;
    // shortest path from node 0 to 4, K = 8
    A = yen(qDGraph, 0, 4, 8);
    cout << "use_globals.cc:\nPrinting the graph:\n";
    for(auto it = A.begin(); it != A.end(); ++it) {
        showlist(*it); 
        cout << "\n";
    }
    return 0; 
} 
