/**
 *Yan To
 *Cheapest Flights Within K Stops
 *https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k){
    // intialize an INF variable that is the max integer representation
    // create 2 distance arrays that can hold the "infinity" value
    int INF = INT_MAX;
    long* dist = (long*)malloc(sizeof(long) * n);
    long* dist_temp = (long*)malloc(sizeof(long) * n);

    // set everything to infinity. Setup for shortest path algorithm calc
    for (int i = 0; i < n; i++){
        dist[i] = INF;
        dist_temp[i] = INF;
    }

    // set source to 0 before beginning shortest path algorithm
    dist[src] = 0;
    dist_temp[src] = 0;

    // Since there are k stops, we will iterate through each edge k times
    while (k >= 0){
	// iterate through every edge in the 2D array flights
	for (int i = 0; i < flightsSize; i++){
		int from = flights[i][0]; // src
		int to = flights[i][1]; // dest
		int price = flights[i][2]; // weight
		
            // compare value of temp array at index "to" checking if it is greater than value of index "from" plus the weight
            if ( dist_temp[to] > dist[from] + price){
                dist_temp[to] = dist[from] + price;
            }
        }
	
	// copy values from temp to the main array 
        for (int i = 0; i < n; i++){
                dist[i] = dist_temp[i];
        }
        k--;
    }

    if (dist[dst] == INF){
        return -1;
    }

    return dist[dst];
}	
