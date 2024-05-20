//Binary Heap
//Programmer Paul Manriquez 

#include <stdio.h>
#include <stdlib.h>

void Insert(int *Heap,int i){
    
    int Temp=0;
    while( (Heap[i]>Heap[i/2]) ){
        if(i==1){break;}
        Temp=Heap[i];
        Heap[i]=Heap[i/2];
        Heap[i/2]=Temp;
        i/=2;
    }
    
}

void Delete(int *Heap, int n, int HeapSize) {
    int x, i, j, Temp;
    x = Heap[1]; // The root element to be deleted
    Heap[1] = Heap[n];
    i = 1;
    j = 2 * i;

    while (j <= n - 1) {
        // Compare the children of the current node
        if (j < n - 1 && Heap[j + 1] > Heap[j]) {
            j = j + 1;
        }

        // Swap if the child is greater than the current node
        if (Heap[j] > Heap[i]) {
            Temp = Heap[i];
            Heap[i] = Heap[j];
            Heap[j] = Temp;
            i = j;
            j = 2 * j;
        } else {
            break;
        }
    }
}


void DisplayHeap(int *Heap,int HeapSize){
    printf("\nDisplaying heap:");
    for(int i=1;i<=HeapSize;i++){
        printf("%d ",Heap[i]);
    }
}

int main(){
    int Heap[]={-1,30,20,15,5,10,12,6,40};    
    int HeapSize= (sizeof(Heap)/sizeof(int))-1;
    
    for(int i=2;i<=HeapSize;i++){
        Insert(Heap,i);
    }
    
    DisplayHeap(Heap,HeapSize);
    
    for(int i=HeapSize;i>=1;i--){//Delete from Heap
        Delete(Heap,i,HeapSize);
    }
    DisplayHeap(Heap,HeapSize);
    return 0;
}

