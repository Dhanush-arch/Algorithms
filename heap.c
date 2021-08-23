#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int maxIndex(int arr[], int x, int y){
    return arr[x] >= arr[y]  ? x:y;
}

void buildMaxHeap (int Arr[], int N, int i)
{
    int left = 2*i;                   
    int right = 2*i +1;
    int largest = i;
    if(left<= N && Arr[left] > Arr[i] )
        largest = left;
    if(right <= N && Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (&Arr[i] , &Arr[largest]);
        buildMaxHeap(Arr, N, largest);
    } 
 }

 void buildMinHeap(int Arr[], int N, int i){
    int left = 2*i;
    int right = 2*i+1;
    int smallest = i;
    if(left <= N && Arr[left] < Arr[i])
        smallest = left;
    if(right <= N && Arr[right] < Arr[smallest])
        smallest = right;
    if(smallest != i){
        swap(&Arr[i], &Arr[smallest]);
        buildMinHeap(Arr, N, smallest);
    }
 }


int extractMax(int arr[], int *size){
    if(size != 0){
        int max = arr[1];
        arr[1] = arr[*size];
        *size = *size -1;
        buildMaxHeap(arr, *size, 1);
        return max;
    }
}


int extractMin(int arr[], int *size){
    int min = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    buildMinHeap(arr, *size, 1);
    return min;
}

int main(){
    int size, index;
    scanf("%d", &size);
    int heapArray[size+1];
    for(index=1;index<=size;index++){
        scanf("%d", &heapArray[index]);
    }

    // for(index=size/2;index >= 1;index--){
    //     buildMaxHeap(heapArray, size, index);
    // }
    for(index=size/2;index >= 1;index--){
        buildMinHeap(heapArray, size, index);
    }

    // for(index=1;index<=size;index++){
    //     printf("%d", heapArray[index]);
    // }

    // while(size >= 1){
    //     printf("%d", extractMax(heapArray, &size));
    // }
    while(size >= 1){
        printf("%d", extractMin(heapArray, &size));
    }

    return 0;
}

/*

input: 
6
2 1 7 6 2 12

output:
12 7 6 2 2 1

*/