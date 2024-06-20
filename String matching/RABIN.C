#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void search(char text[],char pat[]){
	int p=0,t=0,i,j;
	int m=strlen(pat);
	int n=strlen(text);
	int q=366;
	int c=0;


	for(i=0;i<m;i++){
		p+=pat[i];
		t+=text[i];
	}
	p=p%q;
	t=t%q;

	for(i=0;i<=n-m;i++){
		if(p==t){
			for(j=0;j<m;j++){
				if(pat[j]!=text[i+j]){
					break;
				}
			}
			if(j==m){
				c++;
				printf("pattern found at index %d\n",i);
			}
		}
		if(i<n-m){
			t=(t-text[i]+text[i+m])%q;
			if(t<0){
				t=t+q;
			}
		}
	}
	if(c==0){
		printf("Pattern not found");
	}

}


int main(){
	char text[100],pat[100];
	clrscr();
	printf("Enter string:");
	gets(text);
	printf("Enter the pattern:");
	gets(pat);
	printf("....Rabin Karp....\n");
	search(text,pat);
	getch();
	return 0;
}
