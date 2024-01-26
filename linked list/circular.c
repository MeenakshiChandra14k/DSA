#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);

struct Node{
    int data;
    struct Node* next;
};
struct Node *node,*temp,*q,*start=NULL;

struct Node* createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
    return node;
}

void addFront(int info){
    node=createNode(info);
    if(start==NULL){
        start=node;
        node->next=start;
    }
    else{
        node->next=start->next;
        start->next=node;
        start=node;
    }
}

void addLast(int info){
    node=createNode(info);
    q=start;
    if(start==NULL){
        start=node;
        node->next=start;
    }
    else{
        while(q->next!=start){
            q=q->next;
        }
        q->next=node;
        node->next=start;
    }
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
}

void deleteBetween(){
    q=start;
    if(start==NULL){
       printf("\nEmpty list");
    }
    
    else{
        int num;
        printf("Enter the data to be added:");
        scanf("%d",&num);
        while(q->next->data!=num){
            q=q->next;
        }
        temp=q->next;
        q->next=temp->next;
        free(temp);
    }
}

void deleteFront(){
    q=start;
    if(start==NULL){
        printf("\nEmpty list");
    }
    else{
        temp=start->next;
        start=temp->next;
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
        temp=q->next;
        q->next=start;
        free(temp);
    }
}

void display(){
    q=start;
    if(start==NULL){
        printf("\nEmpty list");
    }
    else{
        do{
            printf("%d->",q->data);
            q=q->next;
        }while(q!=start);
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





