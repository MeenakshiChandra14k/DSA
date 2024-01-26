#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);



struct Node{
    int data;
    struct Node* next;
};
struct Node *start=NULL,*node,*temp,*q,*start2=NULL;

struct Node*createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
    return node;
}

void addFront(int info,int l){
    node=createNode(info);
    if(l==1){
        if(start==NULL){
            start=node;
        }
        else{
            node->next=start;
            start=node;
        }
    }
    else{
        if(start2==NULL){
            start2=node;
        }
        else{
            node->next=start2;
            start2=node;
        }
    }
}

void addLast(int info){
    node=createNode(info);
    q=start;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=node;
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
        temp=start;
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
        q->next=temp;
        q->next=NULL;
        free(temp);
    }
}

void display(int l){
    if(l==1){
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
    else{
        q=start2;
        if(start2==NULL){
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
}

void merge(){
    q=start;
    while(q->next!=NULL){
            q=q->next;
    }
    q->next=start2;
    display(1);
}




void main(){
    int n,choice,l;
    while(1){
        printf("\n********Linked List********\n");
        printf("linked list 1 or 2:");
        scanf("%d",&l);
        printf("\n1.add front\n2.add between\n3.add last\n4.delete front\n5.delete between\n6.delete last\n7.display\n8.merge\n9.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter data:");
            scanf("%d",&n);
            addFront(n,l);
            display(l);
            break;
            case 2:
            printf("Enter data:");
            scanf("%d",&n);
            addBetween(n);
            display(l);
            break;
            case 3:
            printf("Enter data:");
            scanf("%d",&n);
            addLast(n);
            display(l);
            break;
            case 4:
            deleteFront();
            display(l);
            break;
            case 5:
            deleteBetween();
            display(l);
            break;
            case 6:
            deleteLast();
            display(l);
            break;
            case 7:
            display(l);
            break;
            case 8:
            merge();
            case 9:
            exit(0);
            default:
            printf("Enter a valid choice");
        }
    }
}





