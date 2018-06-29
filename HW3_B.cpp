#include <iostream>
#define MAX 1000000
using namespace std;

int c[1000000+10];

unsigned long long int mod(unsigned long long int n, unsigned long long int i, unsigned long long int p, unsigned long long int q, unsigned long long int r){
    unsigned long long int res = 0;
    res = ( ((p*(i%MAX))*(i%MAX) % MAX) + (q*(i%MAX) % MAX) + r) % MAX;
    return res;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        unsigned long long int n, k, p, q, r;
        unsigned long long int cur;
        cin >> n >> k >> p >> q >> r;
        
        /*Counting sort*/
        for(int i = 0; i <= MAX; i++)
            c[i] = 0;

        for(int i = 1; i <= n; ++i){
            cur = mod(n, i, p, q, r);
            c[cur] += 1;
        }
        for(int i = 1; i <= MAX; i++){
            c[i] = c[i] + c[i-1];
            if(c[i] >= k){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}