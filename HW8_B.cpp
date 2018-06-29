#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct group{
    int first;
    int second;
    int third;
};

int main(){
    int T;
    cin >> T;
    while(T--){
        group arr[200];    
        int record[1024] = {0};
        queue<int> cur;

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> arr[i].first >> arr[i].second >> arr[i].third;
        record[arr[1].first] = 1;
        record[arr[1].second] = 1;
        record[arr[1].third] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < 1024; j++){
                if(record[j] == 1){
                    cur.push(j);
                    record[j] = 0;
                }
            }
            while(!cur.empty()){
                int num = cur.front();
                cur.pop();
                record[num ^ arr[i].first] = 1;
                record[num ^ arr[i].second] = 1;
                record[num ^ arr[i].third] = 1;
            }
        }

        for(int i = 1023; i >= 0; i--){
            if(record[i] == 1){
                cout << i << endl;
                break;
            }
        }
    }
    getchar();getchar();
    return 0;
}