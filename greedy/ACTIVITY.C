#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int s[50],f[50],d[50];
int n;

void sort(){
	int i,j;
	int t=0;
	/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(f[j]>f[j+1]){
				int temp=f[j];
				int tem=d[j];
				f[j]=f[j+1];
				f[j+1]=temp;
				d[j]=d[j+1];
				d[j+1]=tem;
			}
		}
	}
	for(i=0;i<=n;i++){
		printf("%d:%d:%d  ",s[d[i]],f[i],d[i]);
	}
	//printf("\n%d->",d[i+1]);
	*/
	printf("%d",t);
	for(i=0;i<=n;i++){
		if(s[i]>f[t]){
			printf("->%d",i);
			t=i;
		}
	}
}


int main(){
	int i;
	clrscr();
	printf("Enter the number of activities:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter start time:");
		scanf("%d",&s[i]);
		printf("Enter the finish time:");
		scanf("%d",&f[i]);
		//d[i]=i;
	}
	sort(f);
	//select();
	getch();
	return 0;
}