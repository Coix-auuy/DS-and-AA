#include<stdio.h>
#define SIZE 100  
#define INF 1000000;
int cost[SIZE][SIZE];
int dist[SIZE];
int S[SIZE];
int n,m;
int dijkstra(int v, int j)
{
	int i;
	for(i = 1;i<=n;i++){
		S[i] = 0;
		dist[i] = cost[v][i];
	}
    S[v] = 0;dist[v] = 0;
	int num,w;
    for(num = 1 ; num < n ; num++){	
        int min = INF;   
        int u;  
        for(w = 1 ; w <= n ;w++){	
            if(S[w] == 0 && min > dist[w]){  
                u = w;  
  	            min = dist[w];  
            }  
        }  
        S[u] = 1; 
    	for(w = 1;w<=n;w++){
    		if(S[w] == 0 && (dist[w] > (dist[u] +cost[u][w]))){ 
                dist[w] = dist[u] + cost[u][w];		
        	}  
		}
	}
    return dist[j];
}
int main(){  
    int i,j;  
	n = 6;
	m = 9;
    for(i = 1 ; i <= n ; i++){	
        for(j = 1 ; j <= n ; ++j){  
            cost[i][j] = INF;  
        }  
    }  
    cost[1][2] = 7;
	cost[1][3] = 9;
	cost[1][6] = 14;
	cost[2][3] = 10;
	cost[2][4] = 15;
	cost[3][6] = 2;
	cost[5][6] = 9;
	cost[4][5] = 6;
	cost[3][4] = 11;
	int a = INF;
	for(i = 1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j){
			if(cost[i][j] == a)
				cost[i][j] = cost[j][i];
		}
	}
    int b = dijkstra(1,5);  
    printf("%d",b);  
    return 0;  
}