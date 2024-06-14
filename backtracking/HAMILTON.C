#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100][100];
int k[100];
int c=0;
int n;

int promise(int i){
	int j;

	if(a[k[i-1]][k[i]]==0){
		return 0;
	}
	for(j=0;j<i;j++){
		if(k[j]==k[i]){
			return 0;
		}
	}
	return 1;
}

void search(int i){
	int j;
	if(i==n){
		if(a[k[n-1]][k[0]]==1){
			c++;
			for(j=0;j<n;j++){
				printf("%d\t->",k[j]);
			}
			printf("%d\n",k[0]);
		}
	}
	else{
		for(j=0;j<n;j++){
			k[i]=j;
			if(promise(i)==1){
				search(i+1);
			}
		}
	}
}

int main(){
	int i,j,s;
	clrscr();
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("enter:");
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n...Hamiltonian cycles..\n");
	printf("Enter the starting node:");
	scanf("%d",&s);
	k[0]=s;
	search(1);
	if(c==0){
		printf("no hamiltonian cycle");
	}
	getch();
	return 0;
}