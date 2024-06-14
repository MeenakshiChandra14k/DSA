#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void merge(int arr[],int left,int middle,int right){
    int n1=middle-left+1;
    int n2=right-middle;

    int l[n1],r[n2];

    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    
    for(int j=0;j<n2;j++){
        r[j]=arr[middle+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1&&j<n2){
        if(l[i]<r[j]){
            arr[k++]=l[i++];
        }
        else{
            arr[k++]=r[j++];
        }
    }

    while(i<n1){
        arr[k++]=l[i++];
    }

    while(j<n2){
        arr[k++]=r[j++];
    }

}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int middle=left+(right-left)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
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

    mergeSort(arr,0,n-1);
    printf("\nSorted array\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }


}
