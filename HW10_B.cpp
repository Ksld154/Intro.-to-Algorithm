#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
#include<stack>
using namespace std;


int weighted_vertax[100000];
stack<int> st;
stack<int> st2;

void init(int n){
    for(int i = 1; i <= n; i++)
        weighted_vertax[i] = 0;
}

void DFS_Visit(vector< list<int> >&, int*, int);
int DFS(vector< list<int> >& graph, int color[], int n){
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            DFS_Visit(graph, color, i);
        }
    }
}
void DFS_Visit(vector< list<int> >& graph, int color[], int index){
    color[index] = 1;
    list<int>::iterator itr = graph[index].begin();
    while(itr != graph[index].end()){
        if(color[*itr] == 0){
            DFS_Visit(graph, color, *itr);
        }
        itr++;
    }

    st.push(index);  //small finish time will be at bottom
}



int DFS_Visit2(vector< list<int> >&, int*, int, int*);
int DFS2(vector< list<int> >& graph_tr, int color2[]){
    while(!st.empty()){
        if(color2[st.top()] == 0){

            int cnt_vertax = 1;
            cnt_vertax = DFS_Visit2(graph_tr, color2, st.top(), &cnt_vertax);
            st2.push(st.top());
            weighted_vertax[st.top()] = cnt_vertax;  //maybe do this??
            //cout << "ver" << st.top() << " cnt" << cnt_vertax << endl;
        }
        st.pop();
    }
}
int DFS_Visit2(vector< list<int> >& graph_tr, int color2[], int index, int* cnt){
    color2[index] = 1;
    list<int>::iterator itr = graph_tr[index].begin();
    while(itr != graph_tr[index].end()){
        if(color2[*itr] == 0){
            (*cnt)++;
            //combine(a, b);
            DFS_Visit2(graph_tr, color2, *itr, cnt);
        }
        itr++;
    }
    return *cnt; //the weight of a shrink_vertax
}



int DFS_Visit3(vector< list<int> >&, int*, int, int*);
int DFS3(vector< list<int> >& graph, int color3[], int n){
    int ans = 0;
    while(!st2.empty()){
        int cnt_all = 0;
        cnt_all = DFS_Visit3(graph, color3, st2.top(), &cnt_all);
        //cout << st2.top() << " "<< cnt_all << endl;
        //cout << cnt_all << endl;
        if(cnt_all == n) 
            ans += weighted_vertax[st2.top()];
        st2.pop();

        for(int i = 1; i <= n; i++)
            color3[i] = 0;
    }
    return ans;
}
int DFS_Visit3(vector< list<int> >& graph, int color3[], int index, int* cnt_all){

    //if(graph[index].begin() == graph[index].end())
        //return *cnt_all;
    //(*cnt_all)++;
    //cout << "index " << index << " cnt_all " << *cnt_all << endl;
    color3[index] = 1;
    list<int>::iterator itr = graph[index].begin();
    while(itr != graph[index].end()){
        //cout << *itr << endl;
        if(color3[*itr] == 0){
            //cout << * itr << endl;
            //(*cnt_all)++;
            DFS_Visit3(graph, color3, *itr, cnt_all);
        }
        itr++;
    }
    (*cnt_all)++;
    //cout << *cnt_all << endl;
    return *cnt_all;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;  // n: vertax#, m: edge#
        int color[n+1] = {0};
        int color2[n+1] = {0};
        int color3[n+1] = {0};
        vector< list<int> >graph(n+1);
        vector< list<int> >graph_tr(n+1);
       // vector< list<int> >graph_combine(n+1);

        init(n);

        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph_tr[b].push_back(a);
        }
       
        DFS(graph, color, n);
        DFS2(graph_tr, color2);
        //combine(graph, graph_combine);
        int ans = 0; 
        ans = DFS3(graph, color3, n);
        cout << ans << endl;
        /*while(!st.empty()){
            cout << st.top() << endl;
            st.pop();
        }
        */
    }
    getchar();getchar();
    return 0;
}