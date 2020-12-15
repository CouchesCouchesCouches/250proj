#include "globals.h"

#define NUM_Q_NODES 35
#define NUM_HOM_NODES 23

int SOURCE_NODE = 0;
int DESTINATION_NODE = 2;
int NUM_YEN_PATHS = 5;
int NUM_END_TO_END_ENTANG = 10;

YEN::Graph qDGraph(NUM_Q_NODES);

int HoMstates[NUM_HOM_NODES];

int totalEntanglements = 0;

vector<vector<int> > major_paths;

int multattempt = 0;
int MAXATTEMPTS = 0; //set to 0 if not trying mult entanglements


int BUFFERSIZE = 5;
