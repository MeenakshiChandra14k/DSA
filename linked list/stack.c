#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);



struct Node{
    int data;
    struct Node* next;
};
struct Node *start=NULL,*node,*temp,*q,*tos=NULL;

struct Node*createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
    return node;
}
void addLast(int info){
    node=createNode(info);
    q=start;
    if(start==NULL){
        start=node;
        tos=node;
    }
    else{
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=node;
        node->next=NULL;
        tos=node;
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
        tos=q;
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

void peek(){
    if(tos==NULL){
        printf("Empty stack");
    }
    else{
        printf("tos->%d",tos->data);
    }
}

void main(){
    int n,choice;
    while(1){
        printf("\n********Linked List********\n");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.display\n5.exit\n");
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
            deleteLast();
            display();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            default:
            printf("Enter a valid choice");
        }
    }
}





