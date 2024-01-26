#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct Node*createNode(int co,int pow);



struct Node{
    int coef;
    int power;
    struct Node* next;
};
struct Node *start=NULL,*node,*temp,*q;

struct Node*createNode(int co,int pow){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->coef=co;
    node->power=pow;
    node->next=NULL;
    return node;
}

void addLast(int co, int pow) {
    node = createNode(co, pow);
    if (start == NULL) {
        start = node;
    } else {
        q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = node;
    }
    node->next = NULL;  // Set the next pointer of the new node to NULL
}


void display(){
    q=start;
    if(start==NULL){
        printf("\nEmpty list");
    }
    else{
        while(q!=NULL){
            printf("%dx%d+",q->coef,q->power);
            q=q->next;
        }
        printf("\n");
    }
}

void evaluate(int info){
    q=start;
    int sum=0;
    if(start==NULL){
        printf(0);
    }
    else{
        while(q!=NULL){
            sum=sum+((q->coef)*pow(info,q->power));
            q=q->next;
        }
        printf("sum=%d",sum);
    }
}


void main(){
    int choice,num,p,c;
    while(1){
        printf("\n********Linked List********\n");
        printf("\n1.add\n2.display\n3.evaluate\n4.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter coefficient:");
            scanf("%d",&c);
            printf("Enter power:");
            scanf("%d",&p);
            addLast(c,p);
            display();
            break;
            case 2:
            display();
            break;
            case 3:
            printf("Enter number to be evaluated:");
            scanf("%d",&num);
            evaluate(num);
            break;
            case 4:
            exit(0);
            default:
            printf("Enter a valid choice");
        }
    }
}





