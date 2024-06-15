#include<conio.h>
#include<stdio.h>

void dijkstra(int n,int cost[10][10],int s,int dist[]){
	int i,min,count=1,visited[10],v;
	for(i=1;i<=n;i++){
		visited[i]=0;
		dist[i]=cost[s][i];
	}
	dist[s]=0;
	visited[s]=1;
	while(count<=n){
		min=999;
		for(i=1;i<=n;i++){
			if(dist[i]<min&&visited[i]==0){
				min=dist[i];
				v=i;
			}
		}
		visited[v]=1;
		count++;
		for(i=1;i<=n;i++){
			if(dist[i]>dist[v]+cost[v][i]){
				dist[i]=dist[v]+cost[v][i];
			}
		}
	}
}

int main(){
	int i,j,s,cost[10][10],dist[10],n;
	clrscr();
	printf("enter no.of nodes:");
	scanf("%d",&n);
	printf("read cost matrix:");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("enter:");
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=999;
			}
		}
	}
	printf("\nread source vertex:");
	scanf("%d",&s);
	dijkstra(n,cost,s,dist);
	printf("Shortest path from %d\n",s);
	for(i=1;i<=n;i++){
		if(s!=i){
			printf("%d->%d=%d\n",s,i,dist[i]);
		}
	}
	getch();
	return 0;
}