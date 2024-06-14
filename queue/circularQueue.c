#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define n 5
#define MAX 5
int front=-1,rear=-1,queue[MAX];

void enqueue(int data){
    if(rear==-1&&front==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else if(((rear+1)%n)==front){
            printf("\nQueue full,can't add elements\n");
        }
    else{
        rear=(rear+1)%n;
        queue[rear]=data;
    }
}

void dequeue(){
    if(rear==-1&&front==-1){
        printf("Queue empty");
    }
    else if(rear==front){
        front=rear=-1;
    }
    else{
        front=(front+1)%n;
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
    else if(front>rear){
        printf("front==>");
        for(int i=front;i<n;i++){
            printf("%d==>",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d==>",queue[i]);
        }
        printf("rear");
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
    int num,choice;
    while(1){
        printf("******Queue operations*****");
        printf("\n1.Enqueue\n2.Dequeue\n3.Queue front\n4.Queue rear\n5.Display\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter:");
            scanf("%d",&num);
            enqueue(num);
            display();
            break;
            case 2:
            dequeue(num);
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

