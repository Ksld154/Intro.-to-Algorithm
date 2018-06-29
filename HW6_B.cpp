#include<iostream>
using namespace std;

int dp[1010] = {0};

int find(int num[], int n){
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        
        for(int j = 0; j < i; j++){
            if(num[j] <= num[i]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        if(dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int num[n];
        for(int i = 0; i < n; i++)
            cin >> num[i];
        cout << find(num, n) << endl;
    }
    return 0;
}