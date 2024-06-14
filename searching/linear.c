#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5
int array[MAX];

int linearSearch(int array[],int num){
    int flag=0;
    for(int i=0;i<MAX;i++){
        if(array[i]==num){
            printf("number %d found at index %d",num,i+1);
            flag=1;
            break;
        }
    }
    if(flag==0){
            printf("number not found");
    }
}


void main(){
    int num;
    printf("\n******Linear Search******\n");
    printf("\n---Array---\n");
    for(int i=0;i<5;i++){
        printf("Enter:");
        scanf("%d",&array[i]);
    }
    printf("Enter the the number to search by linear search:");
    scanf("%d",&num);
    linearSearch(array,num);
}