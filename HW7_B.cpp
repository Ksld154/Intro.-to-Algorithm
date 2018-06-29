#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct job{
    long long length;
    long long fine;
    double ratio;
    int ori_index;
};

job jobs[10000];

bool cmp(job a, job b){
    return a.ratio > b.ratio;
}

int main(){
    int M;
    cin >> M;
    while(M--){
        int n;
        unsigned long long ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> jobs[i].length;
            jobs[i].ori_index = i+1;
        }
        for(int i = 0; i < n; i++){
            cin >> jobs[i].fine;
            jobs[i].ratio = (double)jobs[i].fine / (double) jobs[i].length;
        }

        sort(jobs, jobs + n, cmp);

        long long day = 0;
        for(int i = 1; i < n; i++){
            day = day + jobs[i-1].length;
            ans += jobs[i].fine * day;
        }
        cout << ans << endl;

        for(int i = 0; i < n; i++)
            cout << jobs[i].ori_index << " ";
        cout << endl;
    }
    return 0;
}