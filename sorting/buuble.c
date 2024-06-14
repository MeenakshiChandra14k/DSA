#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-i-1);j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(arr[i]>arr[j+1]){
                swap(&arr[i],&arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[50],n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter:");
        scanf("%d",&arr[i]);
    }

    //int arr[]={12,5,4,2,7,8};
    //bubbleSort(arr,n);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    } 

}