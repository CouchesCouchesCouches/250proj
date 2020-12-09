#include "stdc++.h"
#include "yen.h"
#include "globals.h"

using namespace YEN;
using namespace std;

/* Inputs of P4 algorithm are: 
1) S-D pairs from P1, 
2) a major path list and a recovery path list from P2,
3) the k-hop link states of this node/edge from P3, edge by HoM
*/

bool check_link_state(vector<int> segment, int HoMstates[23]){
    for (int i=1; i<segment.size(); i=i+2){
        int h = segment[i];
        if (HoMstates[h - 10] == 0){
            return false;
        }
    }
    return true;
}

void build_graph(){
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

    g.addEdge(16, 33, 20);
    g.addEdge(17, 33, 20);
    g.addEdge(19, 33, 20);
    g.addEdge(19, 34, 20);
    g.addEdge(21, 34, 20);
    g.addEdge(22, 34, 20);
    g.addEdge(28, 33, 20);
    g.addEdge(29, 34, 20);
    g.addEdge(30, 33, 20);
    g.addEdge(31, 34, 20);
}

vector<vector<int> > p4(Graph g, vector<vector<int> > major_path, int HoMstates[23]){
    int k = 1;
    // find all segments
    vector<vector<int> > segments;
    for (int p=0; p<major_path.size(); p++){ // loop through all paths in major_path
        vector<int> path = major_path[p]; // current best path
        //int h = ceil(p.size()/2) - 1;  // skip HoM
        //int n_segments = ceil(h/(k+1));
        for (int i=2; i<=path.size()-1; i=i+4) {  // skip HoM
            if (i == path.size()-1){ // if the current node is the last node
                vector<int> seg = slicing(path, i-2, i);
                segments.push_back(seg);
                break; 
            }  
            vector<int> seg = slicing(path, i-2, i+2);
            segments.push_back(seg);
        }
    }
    //check if segments are viable
    for (int j=0; j<segments.size(); j++){
        vector<int> seg = segments[j];
        // for each segment, check link_state
        vector<vector<int> > recov_segs;
        /*
        initialize recovery segments
        check if any of the recovery segments work
        use that recovery segment as the new segment
        if no recovery segments work, segments[j] will stay the same
            we have to check segments after this too then
        */
        if (check_link_state(seg, HoMstates) == false){
            // int begin = seg.front();
            // int end = seg.back();
            // cout << begin << " to " << end << endl;
            build_graph();  // need to rebuild g before calling yen
            recov_segs = yen(g, seg.front(), seg.back(), 5);
            for (int i=1; i<recov_segs.size(); i++){
                if(check_link_state(recov_segs[i], HoMstates) == true){
                    segments[j] = recov_segs[i];
                    break;
                }
            }
        }   
    }
    return segments;
}

void show_paths(vector<vector<int> > A){
    for(auto it = A.begin(); it != A.end(); ++it) {
        showlist(*it); 
        cout << "\n";
    }
}

int main(){
    // create the graph 
    // int V = 35;  
    // the picture of g is in the link of line 3
    // edge between u, v. The third int is weight
    build_graph();
    // shortest path from node 0 to 2, K = 12
    vector<vector<int> > A = yen(g, 0, 2, 12);
    
    //build_graph();
    // cout << "call yen the 1st time\n";

    //vector<vector<int> > A1 = yen(g, 0, 5, 12);
    //cout << "call yen the 2nd time\n";

    for(int i = 0; i < 23; i++) {
        HoMstates[i] = rand() % 10;
    }
    vector<vector<int> > segments = p4(g, A, HoMstates);
    cout << "segments list" << endl;
    show_paths(segments);

    return 0;
}


