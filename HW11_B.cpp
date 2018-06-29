#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int a[50], b[50];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        sort(b, b+m, cmp);
        int space_left = m;
        bool ans = 1;
        for(int i = 0; i < n; i++){
            int cnt = a[i];
            if(cnt > space_left){
                ans = 0;
                break;
            }
            for(int j = 0; j < m; j++){
                if(cnt > 0){
                    if(cnt > space_left){
                        ans = 0;
                        break;
                    }
                    else if(b[j] > 0){
                        cnt--;
                        b[j]--;
                        if(b[j] == 0) 
                            space_left--;
                    }
                }
            }
            sort(b, b+m, cmp);
        }
        if(ans == 0)
            cout << "No" << endl;  
        else
            cout << "Yes" << endl;      
    }
    return 0;
}
