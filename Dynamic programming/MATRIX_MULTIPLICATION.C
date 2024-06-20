#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

int order(int p[],int i,int j){
	int k;
	int min=INT_MAX;
	int count;
	if(i==j){
		return 0;
	}

	for(k=i;k<j;k++){
		count=order(p,i,k)+order(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(count<min){
			min=count;
		}
	}
	return min;
}

int main(){
	int arr[]={5,4,6,2,7};
	int n=5
	clrscr();
	printf("min cost=%d",order(arr,1,n-1));
	getch();
	return 0;
}
