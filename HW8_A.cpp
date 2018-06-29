#include<iostream>
using namespace std;

struct node{
    int value;
    struct node *l, *r;
};

void BST_insert(struct node* n, int key){
    struct node* pre = n;
    struct node* ins = new node;
    ins->value = key;
    ins->l = NULL;
    ins->r = NULL;

    while(n != NULL){
        if(key < n->value){
            pre = n;
            n = n->l;
            if(n == NULL){
                pre->l = ins;
                return;
            }          
        }
        else if(key > n->value){
            pre = n;
            n = n->r;
            if(n == NULL){
                pre->r = ins;
                return;
            }             
        }
    }  
}

int search(struct node *n, int key){
    
    while(n != NULL){
        if(key == n->value){
            cout << endl;
            return 1;
        }
        else if(key < n->value){
            n = n->l;
            cout << "L";
        }
        else if(key > n->value){
            n = n->r;
            cout << "R";
        }
    }
    return 0;
}


int main(){
    int n, m;
    while(cin >> n >> m){
        int key;
        struct node* root = new node;
        for(int i = 1; i <= n; i++){
            if(i == 1){
                cin >> key;
                root->value = key;
                root->l = NULL;
                root->r = NULL;  
            }
            else{
                cin >> key;
                BST_insert(root, key);
            }
        }
        int ans = search(root, m);
        //cout << ans << endl;
    }
    return 0;
}