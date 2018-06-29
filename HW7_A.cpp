#include<iostream>
using namespace std;

char c[1010];

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        cin >> c;
        
        int ans = 1;
        unsigned long long cur = 0;
        for(int i = 0; i < n; i++){
            cur += (c[i] - '0') % m;  // b%m
            cur = cur % m;
            if(cur == 0){
                if(i != n - 1)
                    ans++;
                cur = 0; 
            }
            else
                cur = (10*cur) % m;
        }
        cout << ans << endl;
    }
    return 0;
}

/* Original idea: if cannot divide, cur = cur*10 + next_char;
   => Connot deal with big number
   => Therefore, need to use some property of module
   => It's clear to see that cur = 10cur+b, which cur at right side is previous number that cannot divide by m, and b is current number.
      And we're checking whether (10cur+b) % m == 0.
    New idea:
      By using module property, original_cur % m == 0 can be replace to ((10a)%m + b%m)%m == 0
      So, just let new_cur = ((10new_cur)%m + b%m) % m
      And check whether new_cur == 0 in each time of loop.
*/ 