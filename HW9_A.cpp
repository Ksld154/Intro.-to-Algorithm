#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
using namespace std;

//int count = 0;  

void DFS_Visit(vector< list<int> >&, int*, int, int*);

/*Do DFS to every vertax (in vector, vertically)*/
int DFS(vector< list<int> >& vertax, int color[], int n, int* count){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){  // if the node is white, then search it.
            DFS_Visit(vertax, color, i, count);

            /*After doing DFS to a node, update the current maximum friends*/
            if(*count > ans)
                ans = *count;
        }
        *count = 0;  //clear it for next node to record the count when doing DFS 
    }
    return ans;
}

/*Do the exact DFS recursive search, start from a node (in list, horizontally)*/
void DFS_Visit(vector< list<int> >& vertax, int color[], int index, int* count){

    color[index] = 1;
    (*count)++; //update it when the node in the list is searched.

    /* Search all of the adjacent nodes */
    list<int>::iterator itr = vertax[index].begin();
    while(itr != vertax[index].end()){
        if(color[*itr] == 0){ //check if the adjacent node is white.
            DFS_Visit(vertax, color, *itr, count);
        }
        itr++;
    }
    return;
}

int main(){
    int n, m;
    int ans;
    int count = 0;
    cin >> n >> m;
    
    vector< list<int> > vertax(n+1);
    int color[n+1] = {0};

    while(m--){
        int a, b;
        cin >> a >> b;
        /* Build edges(bi-direction) */
        vertax[a].push_back(b);
        vertax[b].push_back(a);
    }

    ans = DFS(vertax, color, n, &count);  //pass the address of count!!
    cout << ans << endl;

    getchar();getchar();
    return 0;
}