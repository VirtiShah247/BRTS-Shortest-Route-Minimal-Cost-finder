#include <stdio.h>
#define V 6
#define INF 99999
int sc,des,count=1,a[6];
void printSolution(int dist[V][V],int sc,int des);
void floydWarshall(int graph[V][V],int sc,int des)
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];           
				}
            }
        }
    }
    printSolution(dist,sc,des);
}
void printSolution(int dist[V][V],int sc,int des)
{
	int i,j;
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
        printf("\t 1\t 2\t 3\t 4\t 5\t 6\n\n");
    for (i = 0; i < V; i++) {
    	printf("%d ",(1+i));
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%8s", "INF");
            else
                printf("%8d", dist[i][j]);
        }
        printf("\n");
    }
	printf("\nminimum distance between source station and destination station is %d",dist[sc-1][des-1]);
}
int printintial(int graph[V][V]){
	int i,j;
	  for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", graph[i][j]);
        }
        printf("\n");
    }
}
void printstation(){
	printf("stations are:\n\n1. Ghuma gam: station 1\n2. Iskon mandir: station 2\n3. Bopal: station 3\n4. Iskon cross road: station 4\n5. Sanand Circle: Station 5\n6. Shivranjani: station 6\n\n");
}
int main()
{
	int graph[V][V] = {{ 0, 6, INF, INF,INF,INF},
                        { 6, 0, 5, 1,INF,INF},
                        { INF,5,0,INF,7,10},
                        { INF,1,INF,0,5,3},
						{ INF,INF,7,5,0,6},
						{ INF,INF,10,3,6,0}};
	printstation();
	printf("Intial Distance Between brts station \n\n");
	printintial(graph);
	printf("\n\nEnter Source station number");
	scanf("%d",&sc);
	printf("Enter Destination station number");
	scanf("%d",&des);
	a[0]=sc;
    floydWarshall(graph,sc,des);

    return 0;
}
