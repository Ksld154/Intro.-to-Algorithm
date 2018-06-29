#include<iostream>
#include<cmath>
using namespace std;

int twos[300][300];
int fives[300][300];
int map[300][300];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cur = map[i][j];
            
            while(cur % 2 == 0 && cur >= 2){
                twos[i][j]++;
                cur /= 2;
            }
            while(cur % 5 == 0 && cur >= 5){
                fives[i][j]++;
                cur /= 5;
            }

            if(i == 0 && j == 0) //start point, has nothing to do. 
                continue;
            else if(i == 0){ //construct edges
                twos[i][j] += twos[i][j-1];
                fives[i][j] += fives[i][j-1];
            }
            else if(j == 0){ //construct edges
                twos[i][j] += twos[i-1][j];
                fives[i][j] += fives[i-1][j];
            }
            else{
                twos[i][j] += min(twos[i-1][j], twos[i][j-1]);
                fives[i][j] += min(fives[i-1][j], fives[i][j-1]);
            }
        }
    }
   
    int ans = min(twos[n-1][n-1], fives[n-1][n-1]);
    cout << ans << endl;

    return 0;
}