using namespace std;
#include <bits/stdc++.h>

#define V 5

/* Return index of vertex which is:
 * 1. Not included in mstSet[] 
 * 2. Has minimum key 
 */
int getMinimumKey(vector<int> key, vector<bool> mstSet)
{
    int min = INT_MAX, min_idx = 0;

    for(int i=0;i<V;++i) {
        if(mstSet[i] == false) {
            if(key[i] < min) {
                min = key[i];
                min_idx = i;
            }
        }
    }
    return min_idx;
}

void primMST(int G[V][V])
{
    cout<<"Prim's MST!!"<<endl;
    vector<bool> mstSet(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, 0);

    key[0] = 0; // starting point
    parent[0] = -1; // root of MST

    for(int i=0; i<V-1 ; ++i) {
        int u = getMinimumKey(key, mstSet);
        mstSet[u] = true;

        for (int v=0; v<V; ++v) {
            if((G[u][v] != 0) // adjacent edge should exist
                && (mstSet[v] == false) // should not be in mstSet
                && (G[u][v] < key[v])) // shorter adjacent edge exists
            {
                    parent[v] = u;
                    key[v] = G[u][v];
            }
        }
    }

    // print solution
    cout<<"edge\tedge-weight"<<endl;
    for(int i=1;i<V; ++i)
        cout<<(i-1)<<"-"<<parent[i-1]<<":  "<<G[i-1][parent[i-1]]<<endl;
}

int main() {
  /* Graph G
   *           2    3
   *        (0)--(1)--(2)
   *         |   / \   |
   *        6| 8/   \5 |7
   *         | /     \ |
   *        (3)-------(4)
   *             9          
   */
  int graph[V][V] = {{0, 2, 0, 6, 0},
                     {2, 0, 3, 8, 5},
                     {0, 3, 0, 0, 7},
                     {6, 8, 0, 0, 9},
                     {0, 5, 7, 9, 0},
                    };

  // Print the solution
  primMST(graph);
  return 0;
}
