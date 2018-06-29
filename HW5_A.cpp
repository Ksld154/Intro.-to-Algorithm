#include<iostream>
#include<cmath>
using namespace std;

struct card{
    int rank;
    char suit;
};

int dp[1000] = {0};

int match(struct card cd[], int n){
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;  // 自己本身就是一張

        for(int j = 0; j < i; j++)
            if(cd[i].rank == cd[j].rank || cd[i].suit == cd[j].suit || cd[i].rank == 8 || cd[j].rank == 8)
                dp[i] = max(dp[i], 1 + dp[j]);      
    }
    
    /* find the max value in array */
    int max = 0;
    for(int i = 0; i < n; i++) 
        if(dp[i] > max)
            max = dp[i];
    return max;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        card cd[n];
        for(int i = 0; i < n; i++)
            cin >> cd[i].rank >> cd[i].suit;
        cout << match(cd, n) << endl;
    }
    return 0;
}