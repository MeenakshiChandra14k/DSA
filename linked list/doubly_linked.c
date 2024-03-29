#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *node,*q, *temp, *start=NULL;

struct Node*createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
    node->prev=NULL;
    return node;
}

void addFront(int info){
    node=createNode(info);
    if(start==NULL){
        start=node;
    }
    else{
        node->next=start;
        start=node;
    }
}

void addLast(int info){
    node=createNode(info);
    q=start;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=node;
    node->prev=q;
    node->next=NULL;
}

void addBetween(int info){
    temp=createNode(info);
    q=start;
    int num;
    printf("Enter the info after which data should be added:");
    scanf("%d",&num);
    while(q->data!=num){
        q=q->next;
    }
    temp->next=q->next;
    q->next=temp;
    temp->prev=q;
    temp->next->prev=temp;
}

void deleteBetween(){
    q=start;
    if(start==NULL){
       printf("\nEmpty list");
    }
    
    else{
        int num;
        printf("Enter the data to be deleted:");
        scanf("%d",&num);
        while(q->next->data!=num){
            q=q->next;
        }
        temp=q->next;
        q->next=temp->next;
        temp->next->prev=q;
        free(temp);
    }
}

void deleteFront(){
    q=start;
    if(start==NULL){
        printf("\nEmpty list");
    }
    else{
        temp=start;
        start=temp->next;
        temp->next->prev=NULL;
        free(temp);
    }
}

void deleteLast(){
    q=start;
    if(start==NULL){
       printf("\nEmpty list");
    }
    else{
        while(q->next->next!=NULL){
            q=q->next;
        }
        q->next=temp;
        q->next=NULL;
        free(temp);
    }
}

void display(){
    q=start;
    if(start==NULL){
        printf("\nEmpty list");
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
        printf("\n1.add front\n2.add between\n3.add last\n4.delete front\n5.delete between\n6.delete last\n7.display\n8.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter data:");
            scanf("%d",&n);
            addFront(n);
            display();
            break;
            case 2:
            printf("Enter data:");
            scanf("%d",&n);
            addBetween(n);
            display();
            break;
            case 3:
            printf("Enter data:");
            scanf("%d",&n);
            addLast(n);
            display();
            break;
            case 4:
            deleteFront();
            display();
            break;
            case 5:
            deleteBetween();
            display();
            break;
            case 6:
            deleteLast();
            display();
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            default:
            printf("Enter a valid choice");
        }
    }
}






