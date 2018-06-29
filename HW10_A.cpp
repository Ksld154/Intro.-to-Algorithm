#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int id;
    int a;int b;
    int weight;
    int use;
};
int cmp(edge x, edge y){
    return x.weight < y.weight;
}
int cmp2(edge x, edge y){
    return x.id < y.id;
}

int parent[100000+1];

int findset(int x){
    while(x != parent[x]){
        x = parent[x];
    }
    return x;
}
void unionset(int x, int y){
    x = findset(x);
    y = findset(y);
    parent[x] = y;
}


int main(){
    int n, m;
    cin >> n >> m;
    struct edge graph[m+1];
    for(int i = 1; i <= m; i++){
        cin >> graph[i].a >> graph[i].b >> graph[i].weight;
        graph[i].id = i;
        graph[i].use = 0;
    }

    sort(graph+1, graph+m+1, cmp);

    for(int i = 1; i <= n; i++)
        parent[i] = i;
    //int cnt = 0;
    
    for(int i = 1; i <= m;){
        int cnt = 0;
        for(int j = i; graph[i].weight == graph[j].weight; j++){
            if(findset(graph[j].a) != findset(graph[j].b)){
                graph[j].use = 1;
                //cout << findset(graph[j].a) << " " << findset(graph[j].b) << endl;                
            }
            cnt++;
            //cout <<"cnt" <<  cnt <<endl;
        }

        for(int j = i; j < i+cnt; j++){
            if(findset(graph[j].a) != findset(graph[j].b)){
                unionset(graph[j].a, graph[j].b);
                //cout << graph[j].a << " " << graph[j].b << endl;
            }
        }
        i += cnt;

    }

    sort(graph+1, graph+m+1, cmp2);
    for(int i = 1; i <= m; i++){
        if(graph[i].use == 1)
            cout << "at least one" << endl;
        else
            cout << "none" << endl;
    }
    return 0;
}
