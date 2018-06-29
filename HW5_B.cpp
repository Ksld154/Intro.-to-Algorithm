#include<iostream>
#include<cmath>
using namespace std;

int map[310][310];
int dp[310][310];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    int ans  = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i][j];
            if(dp[i][j] > ans)
                ans = dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}