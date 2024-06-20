#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int c[100][100];

void mincoin(int s,int n){
	int m[50],i,j,k;
	m[0]=0;
	for(i=1;i<=n;i++){
		printf("enter coin val:");
		scanf("%d",&m[i]);
	}
	for(j=0;j<=s;j++){
		c[0][j]=0;
	}
	for(i=1;i<=n;i++){
		c[i][0]=0;
		for(j=1;j<=s;j++){
			int ct=0;
			int l=j;
			int k;
			for(k=i;k>0;k--){
				while(m[k]<=l){
					l=l-m[k];
					ct++;
				}
			}
			if(i==1){
				c[i][j]=ct;
			}
			else{
				if(ct<c[i-1][j]){
					c[i][j]=ct;
				}
				else{
					c[i][j]=c[i-1][j];
				}
			}
		}
	}
	printf("\n...coin change table...\n");

	for(i=0;i<=n;i++){
		for(j=0;j<=s;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("minimum number of coins=%d",c[n][s]);
}

int main(){
	int i,s,n;
	clrscr();
	printf("...Coin exchange dynamic...\n");
	printf("Enter the number of coins:");
	scanf("%d",&n);
	printf("enter the sum:");
	scanf("%d",&s);
	mincoin(s,n);
	getch();
	return 0;
}
