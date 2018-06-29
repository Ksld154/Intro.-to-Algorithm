#include<iostream>
#define SIZE_A 100003;   
#define EMPTY -1000000001
using namespace std;

class node{
public:
    long long num;
    long long cnt;
    node* next;
};

class Hashtable{
public:
    // Constructor!!
    Hashtable(){
        for(int i = 0; i < tablesize; i++){
            HashTable[i] = new node;
            HashTable[i]->num = EMPTY;
            HashTable[i]->cnt = 0;
            HashTable[i]->next = NULL;
        }
    }
    /* Hash function: mod a prime */
    long long hash(long long key){  
        if(key < 0)
            return (key*(-1)) % SIZE_A;
        return key % SIZE_A;
    }
    /* insert node in chainnig hash table */
    void insert(long long key){
        long long index = hash(key);
        if(HashTable[index]->num == EMPTY){  // not collision
            HashTable[index]->num = key;
            HashTable[index]->cnt = 1;
            HashTable[index]->next = NULL;
        }
        else{       /* COLLISION!!! => Chaining(search the list to find the repeated element first) */
            node* ptr = HashTable[index];
            int already = 0;
            while(1){
                if(ptr->num == key){
                    ptr->cnt += 1;  //If repeated, then increment the count of node.
                    already = 1;
                    break;
                }
                if(ptr->next == NULL)
                    break;
                else
                    ptr = ptr->next;
            }
            /* COLLISION with no repeated element => add the node from FRONT!! */
            if(already == 0){
                node *ins = new node;
                ins->num = key;
                ins->cnt = 1;
                ins->next = HashTable[index]->next;
                HashTable[index]->next = ins;
            }
        }
    }
    /* a function, which can search in a chainning hash table */
    int search(long long KeyToSearch){
        long long index = hash(KeyToSearch);
        node* ptr = HashTable[index];
        int count = 0;
        while(ptr != NULL){
            if(ptr->num == KeyToSearch){
                count += ptr->cnt;
            }            
            ptr = ptr->next;
        }
        return count;
    }
private:
    node* HashTable[100010]; 
    static const int tablesize = 100010;
};

int main(){
    int T;
    cin >> T;
    while(T--){
        Hashtable ht;
        long long n, k;
        long long ans = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            long long input;
            cin >> input;

            /* search hash table in O(n/m) time */
            long long target = k - input;
            int amount = ht.search(target);
            ans += amount;
            
            /*put it in the hash table*/
            ht.insert(input);
        }
        cout << ans << endl;
    }
    return 0;
}