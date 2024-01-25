#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int info){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->right=NULL;
    node->left=NULL;
    return node;
}

struct Node* insert(struct Node*root,int info){
    if(root==NULL){
        return createNode(info);
    }
    else if(info<root->data){
        root->left=insert(root->left,info);
    }
    else{
        root->right=insert(root->right,info);
    }
    return root;
}

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root){
    if(root!=NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ",root->data);

    }
}

void postOrder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        postOrder(root->left);
        postOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, v;

    while(1) {
        printf("1. Insert node\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &v);
                root = insert(root, v);
                break;
            case 2:
                printf("Inorder traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    }

    return 0;
}