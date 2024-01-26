#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);



struct Node{
    int data;
    struct Node* next;
};
struct Node *start=NULL,*node,*temp,*q,*front=NULL,*rear=NULL;

struct Node*createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
    return node;
}

void addLast(int info) {
    node = createNode(info);
    if (start == NULL) {
        start = rear = node;
        front = start;
    } else {
        rear->next = node;
        rear = node;
    }
    node->next = NULL;
}


void deleteFront(){
    q=start;
    if(start==NULL){
        printf("\nEmpty list");
    }
    else{
        temp=start;
        start=temp->next;
        front=start;
        free(temp);
    }
}

void peekFront(){
    if(front==NULL){
        printf("Empty queue");
    }
    else{
        printf("front->%d",front->data);
    }
}

void peekRear(){
    if(front==NULL){
        printf("Empty queue");
    }
    else{
        printf("rear->%d",rear->data);
    }
}


void display(){
    q=start;
    if(start==NULL){
        printf("\nEmpty queue");
    }
    else{
        while(q!=NULL){
            printf("%d->",q->data);
            q=q->next;
        }
        printf("\n");
    }
}

void main(){
    int n,choice;
    while(1){
        printf("\n********Linked List********\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek Front\n4.Peek Rear\n5.display\n6.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter data:");
            scanf("%d",&n);
            addLast(n);
            display();
            break;
            case 2:
            deleteFront(n);
            display();
            break;
            case 3:
            peekFront();
            break;
            case 4:
            peekRear();
            break;
            case 5:
            display();
            break;
            case 6:
            exit(0);
            default:
            printf("Enter a valid choice");
        }
    }
}





