#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
char stack[MAX];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }
}

void main(){
    char *e,*x,c;
    char exp[100];
    printf("Enter the expression:");
    scanf("%s",&exp);
    e=exp;
    x=exp;
    while(*e!='\0'){
        push(*e);
        e++;
    }
    /*
    while(top!=-1){
        printf("%c",pop());
    }*/
    int flag=0;
    while(top!=-1){
        if(*x==pop()){
            x++;
        }
        else{
            flag=-1;
            break;
        }
    }
    if(flag==0){
        printf("pallindrome");
    }
    else{
        printf("not a pallindrome");
    }

}