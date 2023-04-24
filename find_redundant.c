
/**
 *Yan To
 *Redundant connections
 *https://leetcode.com/problems/redundant-connection/
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// helper find function to see if the value of the parent set is equal to a target value
int find(int parent[], int val){
    if (parent[val] == val){
        return parent[val];
    }
    parent[val] = find(parent, parent[val]);
    return parent[val];
}

// unionizes the edge so that we can identify which edge is redundant
void union_set(int parent[], int u, int v){
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    parent[root_v] = parent[root_u];
}


// utilize the union find method to find the redundant connection in a graph with edges represented as a 2d array
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    // create a parent array to store each node as a set
    // create a redundant array that will store the redundant edge
    // redundant array can only be of size 2 since an edge is represented as a source to destination
    int* parent = (int*)malloc(sizeof(int) * (edgesSize + 1));
    int* redundant = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    // each node is a parent set
    for (int i = 0; i <= edgesSize; i++){
        parent[i] = i;
    }

    // use helper function to find if set u is equal to set v
    // if not, we will use the union_set helper function to indicate that there is already an edge from that source to that destination
    // Therefore, if we relax that edge again, we will find that redundant connection
    for (int i = 0; i <= edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(parent, u) == find(parent, v)){
            redundant[0] = u;
            redundant[1] = v;
            return redundant;
        }
        union_set(parent, u, v);
    }
    return 0;
}
