#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
using namespace std;

int max_coin = 0;

void DFS_Visit(vector< list<int> >&, int*, int*, int);

void DFS(vector< list<int> >& VertaxList, int color[], int coin[], int n){
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){  
            DFS_Visit(VertaxList, color, coin, i);
        }
    }
}

void DFS_Visit(vector< list<int> >& VertaxList, int color[], int coin[], int index){

    color[index] = 1;
    int head_coin = coin[index];

    list<int>::iterator itr = VertaxList[index].begin();
    while(itr != VertaxList[index].end()){
        if(color[*itr] == 0){ 
            coin[*itr] += head_coin;
            if(coin[*itr] >= max_coin)
                max_coin = coin[*itr];
            DFS_Visit(VertaxList, color, coin, *itr);
        }
        itr++;
    }
    return;
}


int main(){
    int n;
    cin >> n;

    vector< list<int> > VertaxList(n+1);
    int color[n+1] = {0};
    int coin[n+1] = {0};

    for(int i = 1; i <= n; i++)
        cin >> coin[i];
    for(int i = 1; i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        VertaxList[a].push_back(b);
        VertaxList[b].push_back(a);
    }

    DFS(VertaxList, color, coin, n);
    cout << max_coin << endl;

    getchar();getchar();
    return 0;
}