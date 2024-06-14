#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int x[100];

int place(int i, int k){
	int j;
	for(j=1;j<k;j++){
		if(x[j]==i||abs(x[j]-i)==abs(k-j)){
			return 0;
		}
	}
	return 1;
}

void nqueen(int k,int n){
	int i,j;
	for(i=1;i<=n;i++){
		if(place(i,k)){
			x[k]=i;
			if(k==n){
				for(j=1;j<=n;j++){
					printf("%d\t",x[j]);
				}
				printf("\n");
			}
			else{
				nqueen(k+1,n);
			}
		}
	}
}

int main(){
	int n;
	clrscr();
	printf("Enter the number of queens:");
	scanf("%d",&n);
	printf("\n...Placing %d queens in %dx%d chess board...\n",n,n,n);
	nqueen(1,n);
	getch();
	return 0;
}