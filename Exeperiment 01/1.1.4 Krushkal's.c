/*Write a C program to construct the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph using Kruskal’s Algorithm.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void kruskalMST(int **cost, int V) {
	int parent[V];
	for(int i = 0; i < V; i++)
		parent[i] = i;
	int edges = 0, minCost = 0, edgeNo = 0;
	while(edges < V - 1){
		int min = 9999;
		int u = -1, v = -1;
		for(int i = 0; i < V; i++){
			for(int j = i; j < V; j++){
				if(cost[i][j] < min){
					min = cost[i][j];
					u = i;
					v = j;
				}
			}
		}
		int ru = u;
		while(parent[ru] != ru)
			ru = parent[ru];
		int rv = v;
		while(parent[rv] != rv)
			rv = parent[rv];
		if(ru != rv){
			parent[rv] = ru;
			printf("Edge %d:(%d, %d) cost:%d\n", edgeNo++,u,v,min);
			minCost += min;
			edges++;
		}
		cost[u][v] = cost[v][u] = 9999;
	}
	printf("Minimum cost= %d\n", minCost);
}
int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));
    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);
    kruskalMST(cost, V);
    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);
    return 0;
}
