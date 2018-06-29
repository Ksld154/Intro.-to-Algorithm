#include<iostream>
#include<cstdio>
using namespace std;

int CountWorst; 

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int l, int r){
    int x = A[r];
    int i = l - 1;
    for (int j = l; j <= r-1; j++){
        CountWorst--;
        if(A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void QuickSort(int A[], int l, int r){
    if(l < r){
        int q = Partition(A, l, r);
        QuickSort(A, l, q-1);
        QuickSort(A, q+1, r);
        for(int i = l; i <= r; i++)
            cout << A[i] << " ";
        cout << endl;
    }

}

int main(int argc, char const *argv[])
{
    int T, N;
    int A[1000+10];
    cin >> T;

    while(T--){
        cin >> N;
        for(int i = 1; i <= N; i++)
            cin >> A[i];

        CountWorst = N*(N-1)/2;
        QuickSort(A, 1, N);

       if(CountWorst == 0)
            cout << "Yes" << endl;
        else
            cout << "No"  << endl;

        for (int i = 1; i <= N; i++)
            cout << A[i] << " ";
        cout << endl;        
    }
    getchar();
    return 0;
}