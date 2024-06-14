#include<stdio.h>
#include<stdlib.h>

int visited[5]={0,0,0,0,0};
int a[5][5];

void DFS(int i){
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<5;j++){
        if(a[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}

int main(){
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    DFS(4);
    return 0;
}