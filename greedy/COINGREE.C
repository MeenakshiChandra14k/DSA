#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i,k,s,m[50],c=0;
	clrscr();
	printf("Enter the number of coins:");
	scanf("%d",&n);
	printf("Enter the sum:");
	scanf("%d",&s);
	for(i=1;i<=n;i++){
		printf("Enter coin value:");
		scanf("%d",&m[i]);
	}
	for(k=n;k>0;k--){
		while(m[k]<=s){
			s=s-m[k];
			c++;
		}
	}
	printf("minimum number of coins=%d",c);
	getch();
	return 0;
}