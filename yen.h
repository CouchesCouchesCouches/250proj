#ifndef YEN_H
#define YEN_H

#include "stdc++.h"
#include <iostream>
#include <omnetpp.h>
using namespace omnetpp;

using namespace std; 
namespace YEN {

// iPair ==>  Integer Pair 
typedef pair<int, int> iPair; 
typedef pair<int, vector<int> > vPair;


class Graph 
{ 
    public:
        int V;
        list< pair<int, int> > *adj; 
        vector<int> dist;  // to store distance from source
     
        Graph(int V); // Constructor  
        Graph(const Graph &rhs);
    
        // function to add an edge to graph 
        void addEdge(int u, int v, int w);
    
        void delEdge(int u, int v);
    
        vector<int> findPath(int parent[], int s, int d);
        // prints shortest path from s 
        vector<int> dijkstra(int src, int des);
    };
}

//void showlist(vector<int> g);
inline void showlist(vector<int> g) { 
    for(auto it = g.begin(); it != g.end(); ++it) 
        EV << *it <<' ';
        //cout << *it << ' ';
} 

// helper function to slice vector from X to Y, inclusive
vector<int> slicing(vector<int>& arr, int X, int Y); 

// psudocode: https://en.wikipedia.org/wiki/Yen%27s_algorithm
vector<vector<int> > yen(YEN::Graph g, int s, int d, int K);


#endif
