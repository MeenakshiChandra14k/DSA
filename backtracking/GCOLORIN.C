#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int a[5][5]={{0,1,1,1,0},{1,0,1,0,0},{1,1,0,1,0},{1,0,1,0,0},{0,0,0,0,0}};
int c[5];
int m=5;
int n=5;


int promise(int i){
	int j;
	for(j=0;j<i;j++){
		if((a[i][j]==1)&&(c[i]==c[j])){
			return 0;
		}
	}
	return 1;
}

void color(int i){
	int j;
	if(i==n){
		for(j=0;j<n;j++){
			printf("%d\t",c[j]);
		}
	}
	else{
		for(j=1;j<=m;j++){
			c[i]=j;
			if(promise(i)){
				break;
			}
		}
		color(i+1);
	}
}

int main(){
	clrscr();
	c[0]=1;
	color(1);
	getch();
	return 0;
}