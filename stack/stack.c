#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int tos=-1;
int stack[MAX];

void push(){
    int info;
    if(tos==(MAX-1)){
        printf("Overflow condition:cannot push elements");
    }
    else{
        tos++;
        printf("Enter the element");
        scanf("%d",&info);
        stack[tos]=info;
        printf("Stack after push opertion is:");
    }

}

void pop(){
    if(tos==-1){
        printf("Underflow condition:cannot pop elements");
    }
    else{
        printf("Popped element is %d",stack[tos]);
        tos--;
        printf("Stack after pop opertion is:");
    }


}

void display(){
    if(tos==-1){
        printf("Underflow condition:cannot pop elements");
    }
    else{
        for(int i=tos;i>=0;i--){
            printf("\n\t\t\t%d",stack[i]);
            printf("\n\t\t__________");
        }
    }
}

void stackTop(){
    if(tos==-1){
        printf("Underflow condition:cannot pop elements");
    }
    else{
        printf("Element at the top of the stack is %d",stack[tos]);
    }
}

int main(){
    int choice;
    while(1){
        printf("\n******Stack operations******");
        printf("\n1.Push\n2.Pop\n3.Display\n4.StackTop\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            display();
            break;
            case 2:
            pop();
            display();
            break;
            case 3:
            display();
            break;
            case 4:
            stackTop();
            break;
            case 5:
            exit(0);
            default:
            printf("enter a valid choice:");
        }
    }
    return 0;
}