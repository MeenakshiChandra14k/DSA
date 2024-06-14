#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    for(int j=low+1;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i],&arr[low]);
    return i;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
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

    printf("\noriginal array\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }

    quickSort(arr,0,n-1);
    printf("\nSorted array\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }


}