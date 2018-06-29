#include<iostream>
#include<cstdio>
using namespace std;


void printArray(long long int a[], int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


int main(int argc, char const *argv[])
{
    int M;
    cin >> M;
    while(M--){
        long long  p, q, r, x, y, z, N;
        long long  a, b;
        long long  ans;
        cin >> p >> q >> r;
        cin >> x >> y >> z >> N;
        int a_cnt = 0, b_cnt = 0, i = 0;
        while(i < N){
            a = p*a_cnt*a_cnt + q*a_cnt + r;
            b = x*b_cnt*b_cnt + y*b_cnt + z;

            if(a < b){
                ans = a;
                a_cnt++;
            }
            else{
                ans = b;
                b_cnt++;
            }

            i++;
        }
        cout << ans << endl;
    }    
    return 0;
}