#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5
int array[MAX];

int binarySearch(int array[],int low,int high,int num){
    if (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == num) {
            return mid;
        } else if (array[mid] > num) {
            high = mid - 1;
            return binarySearch(array, low, high, num);
        } else {
            low = mid + 1;
            return binarySearch(array, low, high, num);
        }
    }
    return -1;
}

void main(){
    int num;
    int result=-1;
    printf("\n******Binary Search******\n");
    printf("\n---Array---\n");
    for(int i=0;i<5;i++){
        printf("Enter:");
        scanf("%d",&array[i]);
    }
    printf("Enter the the number to search by Binary search:");
    scanf("%d",&num);
    result=binarySearch(array,0,MAX,num);
    if(result==-1){
        printf("Number %d not found",num);
    }
    else{
        printf("Number %d found at index %d",num,result+1);
    }
}