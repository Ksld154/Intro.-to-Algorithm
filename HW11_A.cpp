#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
#define INFI 10000000
using namespace std;

struct node{
    int vertax;
    int weight;
};
struct node_path{
    int dist;
    int parent;
};
struct query{
    int start, dest;
};

struct node2{
    int vertax;
    int path_len;
    int color;
};

int BellmanFord(vector<list<node> >& VertaxList, int n, int m, vector<node_path>& short_path, int src){
    for(int i = 1; i <= n; i++){
        short_path[i].dist = INFI;
        short_path[i].parent = -1;
    }
    short_path[src].dist = 0;

    for(int i = 0; i <= n-1; i++){
        for(int j = 0; j <= n; j++){
            list<node>::iterator itr = VertaxList[j].begin();

            while(itr != VertaxList[j].end()){
                if((*itr).weight == INFI){
                    itr++;
                    continue;
                }
                else if(short_path[j].dist + (*itr).weight < short_path[(*itr).vertax].dist){
                    short_path[(*itr).vertax].dist = short_path[j].dist + (*itr).weight;
                    short_path[(*itr).vertax].parent = j;
                }
                itr++;
            }

        }
    }

    printf("\nThe short_path List-\n");
    for (int i = 0; i < short_path.size(); ++i) {
        printf("short_pathList[%d] ", i);
        printf("dist:%3d  parent:(%d)", short_path[i].dist, short_path[i].parent);
        printf("\n");
    }
}

int Dijkstra(vector<list<node> >& VertaxList, int n, int m, vector<node_path>& short_path,vector<node2> pq, int start, int end){
    int i = start;
    pq[i].path_len = 0;
    pq[i].color = 1;

    for(int i = 1; i <= n; i++){
        if(pq[i].color == 0){
            int min = INFI;
            int min_index = 0;
            for(int i = 1; i <= n; i++){
                if(pq[i].path_len < min){
                    min = pq[i].path_len;
                    min_index = i;
                }
            }

            list<node>::iterator itr = VertaxList[min_index].begin();
            while(itr != VertaxList[min_index].end()){
                if(pq[min_index].path_len + (*itr).weight < pq[(*itr).vertax].path_len){
                    pq[min_index].color = 1;
                    pq[(*itr).vertax].path_len = pq[min_index].path_len + (*itr).weight;
                    pq[(*itr).vertax].path_len = pq[(*itr).vertax].path_len + short_path[(*itr).vertax] - short_path[min_index];
                }
                itr++;
            }
        }
    }
}

int main(){
    int n, m, q;  //n: node#,  m:edge# 
    int src = 0;
    cin >> n >> m >> q;

    vector< list<node> > VertaxList(n+1);
    vector<node_path> short_path(n+1);
    vector<query> qu(q+1);
    vector<node2> pq(n+1);
    for(int i = 1; i <= m; i++){
        node tmp;
        int a;
        cin >> a >> tmp.vertax >> tmp.weight;
        VertaxList[a].push_back(tmp);
    }
    for(int i = 1; i <= n; i++){
        node tmp2 = {i, 0};
        VertaxList[src].push_back(tmp2);
    }
    for(int i = 1; i <= q; i++){
        cin >> qu[i].start >> qu[i].dest;
    }

    for(int i = 1; i <= n; i++){
        pq[i].vertax = i;
        pq[i].path_len = INFI;
        pq[i].color = 0;
    }



    // Printing Adjacency List
    printf("\nThe Adjacency List-\n");
    for (int i = 0; i < VertaxList.size(); ++i) {
        printf("adjacencyList[%d] ", i);
         
        list< node >::iterator itr = VertaxList[i].begin();
        while (itr != VertaxList[i].end()) {
            printf(" -> %d(%d)", (*itr).vertax, (*itr).weight);
            ++itr;
        }
        printf("\n");
    }

    BellmanFord(VertaxList, n, m, short_path, src);

    /* Re-weighting */
    for(int i = 1; i <= n; i++){
        list<node>::iterator itr = VertaxList[i].begin();
        while(itr != VertaxList[i].end()){
            (*itr).weight = (*itr).weight + short_path[i].dist - short_path[(*itr).vertax].dist;
            itr++;
        }
    }
    printf("\nThe Adjacency List-\n");
    for (int i = 0; i < VertaxList.size(); ++i) {
        printf("adjacencyList[%d] ", i);
         
        list< node >::iterator itr = VertaxList[i].begin();
        while (itr != VertaxList[i].end()) {
            printf(" -> %d(%d)", (*itr).vertax, (*itr).weight);
            ++itr;
        }
        printf("\n");
    }

    /* Dijkstra */
    Dijkstra(VertaxList, n, m, short_path, pq, 2, 3);
    cout << 
    getchar();getchar();
    return 0;
}