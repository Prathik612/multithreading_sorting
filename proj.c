#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//structure for arguments
typedef struct{
    int *arr;   //array
    int n;      //size of array
}arguments;

//func to swap 2 variables
void swap(int *a, int *b) {
  int temp=*a;
  *a=*b;
  *b=temp;
}

void printArray(arguments *arg){
    for(int i=0; i<arg->n; i++){
        printf("%d ", arg->arr[i]);
    }
    printf("\n");
}

//sorts array in ascending using selection sort
void *sel_asc(void *arg){
    arguments *a=(arguments*)arg;

    printArray(a);

    for(int step=0; step<(a->n)-1; step++) {
        int min=step;
        for(int i=step+1; i<a->n; i++) {
            if (a->arr[i] < a->arr[min])
                min=i;
        }
    
        swap(&a->arr[min], &a->arr[step]);
        printArray(a);
    }

    //return (void*)a;
}

//sorts array in descending using selection sort
void *sel_dsc(void *arg){
    arguments *a=(arguments*)arg;

    printArray(a);

    for(int step=0; step<(a->n)-1; step++) {
        int min=step;
        for(int i=step+1; i<a->n; i++) {
            if(a->arr[i] > a->arr[min])
                min=i;
        }

        swap(&a->arr[min], &a->arr[step]);
        printArray(a);
    }

    //return (void*)a;
}

void *merge_asc(void *arg){

}

void *merge_dsc(void *arg){

}

int main(){
    arguments arg;
    pthread_t thread[2];
    int option;

    printf("Number of elements: ");
    scanf("%d", &arg.n);

    arg.arr=(int*)malloc(arg.n*sizeof(int));

    printf("Enter the elements: \n");

    for(int i=0; i<arg.n; i++){
        printf("Element %d: ",i);
        scanf("%d", &arg.arr[i]);        
    }

    printf("1. Selection Sort\n2. Merge Sort\n-> ");
    scanf("%d", &option);

    switch(option){
        case 1:
            pthread_create(&thread[0],NULL,&sel_asc,(void*)&arg);
            //pthread_create(&thread[1],NULL,&sel_dsc,(void*)&arg);
            pthread_join(thread[0],NULL);
            //pthread_join(thread[1],NULL);    
            break;
        case 2:
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}