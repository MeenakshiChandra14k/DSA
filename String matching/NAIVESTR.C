#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void search(char pat[],char text[]){
	int m=strlen(pat);
	int n=strlen(text);
	int i,j;
	int count=0;
	for(i=0;i<n-m+1;i++){
		int flag=0;
		for(j=0;j<m;j++){
			if(pat[j]!=text[j+i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			count++;
			printf("Pattern found at index %d\n",i);
		}

	}
	if(count==0){
		printf("Pattern not found");
	}
}

int main(){
	char pat[100],text[100];
	clrscr();
	printf("Enter the string:");
	scanf("%s",&text);
	printf("Enter the pattern to search:");
	scanf("%s",&pat);
	search(pat,text);
	getch();
	return 0;
}

