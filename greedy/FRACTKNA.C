#include<stdio.h>
#include<conio.h>
#include<limits.h>

float maxprofit(float p[],int w[],int c,int n){
	int sack=0;
	float profit=0;
	int k;
	int i;
	for(i=0;i<n;i++){
		sack=sack+w[i];
		profit=profit+p[i];
		printf("\n%f,%f\n",sack,profit);
		if(sack>c){
			sack=sack-w[i];
			profit=profit-p[i];
			k=i;
			break;
		}
	}
	if(sack==c){
		return profit;
	}else{
		profit=profit+((c-sack)*p[k])/w[k];
		return profit;
	}
}


int main(){
	float p[]={24,20,16};
	int w[]={14,18,10};
	int c=40;
	clrscr();
	printf("...Fractional knapsack...");
	printf("\nmax profit=%f",maxprofit(p,w,c,3));
	getch();
	return 0;
}