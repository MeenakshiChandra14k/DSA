#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);



struct Node{
    int data;
    struct Node* next;
};
struct Node *start=NULL,*node,*temp,*q,*q1,*q2,*start2=NULL,*start3=NULL;

struct Node*createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
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
    }
    else if(l==2){
        q=start2;
    }
    else{
        q=start3;
    }
    if(q==NULL){
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

void split(int s) {
    printf("split...");
    q = start;
    q1 = start2;
    q2=start3;
    // Create new nodes for the second list (start2)
    for (int i = 0; i < s && q != NULL; i++) {
        node = createNode(q->data);
        if (i == 0) {
            start2 = node;  // Set start2 to the first node of the new list
            q1 = start2;    // Set q1 to the start of the new list
        } else {
            q1->next = node;
            q1 = q1->next;
        }
        q = q->next;
    }
     
    if (q1 != NULL) {
        q1->next = NULL;
    }

    printf("\nsplitting...\n");
    display(2);
    for (int i = 0; q != NULL; i++) {
    node = createNode(q->data);
    if (i == 0) {
        start3 = node;  // Set start3 to the first node of the new list
        q2 = start3;    // Set q2 to the start of the new list
    } else {
        q2->next = node;
        q2 = q2->next;
    }
    q = q->next;
    }

    if (q2 != NULL) {
        q2->next = NULL;
    }

    display(3);

}



void main(){
    int n,choice,s;
    while(1){
        printf("\n********Linked List********\n");
        printf("\n1.add front\n2.add between\n3.add last\n4.delete front\n5.delete between\n6.delete last\n7.display\n8.split\n9.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter data:");
            scanf("%d",&n);
            addFront(n);
            display(1);
            break;
            case 2:
            printf("Enter data:");
            scanf("%d",&n);
            addBetween(n);
            display(1);
            break;
            case 3:
            printf("Enter data:");
            scanf("%d",&n);
            addLast(n);
            display(1);
            break;
            case 4:
            deleteFront();
            display(1);
            break;
            case 5:
            deleteBetween();
            display(1);
            break;
            case 6:
            deleteLast();
            display(1);
            break;
            case 7:
            display(1);
            break;
            case 8:
            printf("enter position to split at:");
            scanf("%d",&s);
            split(s);
            case 9:
            exit(0);
            default:
            printf("Enter a valid choice");
        }
    }
}





