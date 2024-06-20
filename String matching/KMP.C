#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//int lps[100];

void computelps(char pat[], int m,int lps[]){
	int len=0;
	int i=1;
	lps[0]=0;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i+=1;
		}else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i+=1;
			}
		}
	}

}

void search(char text[],char pat[]){
	int n= strlen(text);
	int m=strlen(pat);
	int i=0,j=0,c=0;
	int lps[100];
	computelps(pat,m,lps);
	while(i<n){
		if(text[i]==pat[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
		if(j==m){
			c++;
			printf("pattern found at index %d\n",i-j);
			j=lps[j-1];
		}
	}
	if(c==0){
		printf("pattern not found");
	}
}

int main(){
	char text[100],pat[100];
	clrscr();
	printf("Enter the string");
	gets(text);
	printf("Enter the pattern:");
	gets(pat);
	printf("\n...KMP...\n");
	search(text,pat);
	getch();
	return 0;
}
