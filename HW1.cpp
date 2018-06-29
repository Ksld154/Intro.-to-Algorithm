#include<iostream>
using namespace std;

void pow(int M[2][2], int n);
void print(int M[2][2]);

int fib(int n){
    int F[2][2] = {{1, 1}, {1, 0}};
    if(n == 0 || n == 1)
        return 1;
    else{
        pow(F, n-1);
        return F[0][0];
    }
}

void mul(int A[2][2], int B[2][2]){ //mod 29989
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(A[i][j] >= 29989)
                A[i][j] = A[i][j]%29989;
            if(B[i][j] >= 29989)
                B[i][j] = B[i][j]%29989;
        }
    }
    int ans[2][2];
    ans[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    ans[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    ans[1][0] = A[0][0]*B[1][0] + A[1][0]*B[1][1];
    ans[1][1] = A[0][1]*B[1][0] + A[1][1]*B[1][1];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(ans[i][j] >= 29989)
                ans[i][j] = ans[i][j]%29989;
        }
    }
    //????是傳指標進來 所以可以直接改參數 
    A[0][0] = ans[0][0];
    A[0][1] = ans[0][1];
    A[1][0] = ans[1][0];
    A[1][1] = ans[1][1];
}

void pow(int M[2][2], int n){
    if(n == 0 || n == 1)
        return;
    else{
        int F[2][2] = {{1, 1}, {1, 0}};
        pow(M, n/2);

        mul(M, M);
        //print(M);
        
        if(n % 2 != 0)
            mul(M, F);
    }
}
void print(int M[2][2]){
    cout << M[0][0] << " " << M[0][1] << endl;
    cout << M[1][0] << " " << M[1][1] << endl;
}

int main(){
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << fib(n) << endl;
    }
    return 0;
}
