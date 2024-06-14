#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5
int front=-1,rear=-1,queue[MAX];

void enqueue(int data){
    if(rear==(MAX-1)){
        printf("\nQueue full, can't add elements\n");
    }
    else{
        if(rear==-1){
            front=0;
        }
        rear++;
        queue[rear]=data;
    }
}

void dequeue(){
    if(front==-1){
        printf("\nQueue empty, cant delete\n");
    }
    else{
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }

}

void queueFront(){
    if(front==-1){
        printf("\nQueue empty\n");
    }
    else{
        printf("front->%d",queue[front]);
    }

}

void queueRear(){
    if(rear==-1){
        printf("\nQueue empty\n");
    }
    else{
        printf("rear->%d",queue[rear]);
    }

}

void display(){
    if(rear==-1){
        printf("\nQueue empty\n");
    }
    else{
        printf("front==>");
        for(int i=front;i<=rear;i++){
            printf("%d==>",queue[i]);
        }
        printf("rear");
    }
}

void main(){
    int n,choice;
    while(1){
        printf("******Queue operations*****");
        printf("\n1.Enqueue\n2.Dequeue\n3.Queue front\n4.Queue rear\n5.Display\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter:");
            scanf("%d",&n);
            enqueue(n);
            display();
            break;
            case 2:
            dequeue(n);
            display();
            break;
            case 3:
            queueFront();
            break;
            case 4:
            queueRear();
            break;
            case 5:
            display();
            break;
            case 6:
            exit(0);
            default:
            printf("Enter a valid choice:");
            
        }
    }
}

