#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void floyd(int cost[10][10],int n){
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				cost[i][j]=minimum(cost[i][j],cost[i][k]+cost[k][j]);
			}

		}
	}
}


int minimum(int a,int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}

int main(){
	int i,j,cost[10][10],n;
	clrscr();
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\nread cost\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Enter:");
			scanf("%d",&cost[i][j]);
		}
	}
	floyd(cost,n);
	printf("\nAll pair shortest path\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}