#include<iostream>
#include<cstdio>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int A[], int i, int Asize){
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;

    if(l <= Asize && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if(r <= Asize && A[r] > A[largest])
        largest = r;

    if(largest != i){
        swap(&A[i], &A[largest]);
        MaxHeapify(A, largest, Asize);
    }
}

void BuildMaxHeap(int A[], int Asize){
    for(int i = Asize/2; i >= 1; i--)
        MaxHeapify(A, i, Asize);
}

void HeapSort(int A[], int Asize){
    
    BuildMaxHeap(A, Asize);

    for(int i = Asize; i >= 2; i--){
        swap(&A[i], &A[1]);
        MaxHeapify(A, 1, i-1);
    }
}

void PrintArray(int A[], int Asize){
    for(int i = 1; i <= Asize; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int N;
    int arr[10000+10];

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    BuildMaxHeap(arr, N);
    PrintArray(arr, N);

    HeapSort(arr, N);
    PrintArray(arr, N);

    getchar();
    getchar();
    return 0;
}
