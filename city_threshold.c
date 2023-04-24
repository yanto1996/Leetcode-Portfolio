/**
 *Yan To
 *1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 *https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 */


// This function will perform floyd-warshall algorithm to find the city with the smallest number of reachable cities at a distance
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    // Create a n * n array
    int INF = INT_MAX;
    int** shortest = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++){
        shortest[i] = (int*)malloc(sizeof(int) * n);
    // Set equal x y boxes to be 0 and the rest to INF before floyd-warshall traversal
        for (int j = 0; j < n; j++){
            if ( i == j){
                shortest[i][j] = 0;
            }

            else{
                shortest[i][j] = INF;
            }
        }
    }

    // intialize the weights into the n * n array
    for (int i = 0 ; i < edgesSize; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        shortest[u][v] = w;
        shortest[v][u] = w;
    }

    // go through each node and check the shortest path between j and k through i, if so update
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (shortest[j][i] != INF && shortest[i][k] != INF){
                    if (shortest[j][k] > shortest[j][i] + shortest[i][k]){
                        shortest[j][k] = shortest[j][i] + shortest[i][k];
                    }
                }
            }
        }
    }

    // intialize 2 more variables max which is INF and a temp answer varaible to 0
    int max = INF;
    int answer = 0;

    // loop through the whole 2d array and check if the value at index [i][j] is atleast the distance threshold
    // increment count if so
    // Max will be the count and answer will be updated to the node #
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (i != j && shortest[i][j] <= distanceThreshold){
                count++;
            }
        }
	
        if (max >= count){
            max = count;
            answer = i;
        }
    }
    return answer;
}
