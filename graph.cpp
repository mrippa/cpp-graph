#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
const int size = 7;

inline double prob() {

    return (double) rand() / (double)RAND_MAX;

}

inline void printGraph( bool* g[], const int size) {

    for(int r=0; r<size; ++r) {
        for(int c=0; c<size; ++c)
            cout << g[r][c] <<  " " ;
        cout << endl;
    }
}

inline bool is_connected(bool *graph[], const int size) {

    int old_size=0, c_size=0;
    bool* close = new bool[size];
    bool* open = new bool[size];
    for(int r=0; r<size; ++r) 
        open[r] = close[r] = false; //Every node initialy unconnected

    open[0] = true; //except the starting node

    //Add to close
    while(c_size < size) {
        for(int r=0; r<size; ++r) {
            old_size = c_size;
            if (open[r] && (close[r] == false)) {
                close[r] = true;
                c_size++;

                //Add to open
                int k = 0;
                for(int c=0; c<size; ++c) {
                    open[c] = open[c] || graph[r][c];
                    k=c-1;
                }

                cout << "open = " << open[k] << endl;
            }

        }
        //Are we done?
        cout << "c_size = " << c_size << endl;
        cout << "old_size = " << old_size << endl;
        if(c_size == size) return true; //Connected
        if(old_size == c_size) return false; //Unconnected
    }
}

int main() {


    bool** graph;

    srand(time(0));
    graph = new bool*[size];

    for(int i=0; i<size; ++i) {
        graph[i] = new bool[size];

    }


    for (int i=0; i<size; ++i) 
        for (int j=i; j<size; ++j) 
            if (i == j)
                graph[i][j] = false; // no loops
            else if (i==5 && j==6 )
                graph[i][j] = graph[j][i]= 1;
            else
                graph[i][j] = graph[j][i] = (prob() < 0.19);


    printGraph(graph, size);

    cout << "Graph is Connected?: " << is_connected(graph, size) << endl;
}


