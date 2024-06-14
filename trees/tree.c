#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node*createNode(int info);

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root=NULL,*temp,*node;

struct Node*createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void insert(info){
    node=createNode(info)
    if(root==NULL){
        root=node;
    }
    else if(info>(root->data)){
        
    }
}