#include<bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class Entry{
    K key;
    V value;
public:
    Entry* next;//next pointer like a linked list
    Entry(){
        key = -1, value = -1, next = NULL;
    }

    Entry(K key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
};


template <typename K, typename V>
class HashMap{
    const int INITIAL_SIZE=1<<4;//size is 16 for initiality
    const int MAX_CAPACITY= 1<<30;// 2^30 is the maximum capacity

    vector<Entry<K,V>*> *hashTable; // it has a hashtable

public:
    HashMap(int capacity){
        // make a hashmap of cap
        int cap = getCap(capacity);
        hashTable = new vector<Entry<K,V>()>(cap);
        // fill entries in vector
    }

    int getCap(int x){
        int cap=x-1;
        x|=x>>>1;
        x|=x>>>2;
        x|=x>>>4;
        x|=x>>>8;
        x|=x>>>16;
        return (x<0)?1:(x>=MAX_CAPACITY:MAX_CAPACITY:x+1);
    }

    void put(K key, V value){
        // generate a hashcoard
        int hashcode = /..........;// get hashcode from the key
        Entry* node = hashTable[hashCode];

        // check if it is a null pointer 
        if(node == NULL){
            // new node
            // insert
            hashTable [hashcode] = NEWNODE;
        }

        else{//collision has happened
            Entry *previousCode = node;
            // ierate the linked list uptil pre->next!=NULL
            // if a key is already there return
            
            //after finding
            // inset at last
        }
    }

    V get(K key){
        // find hascode again
        // while(node!=null){
            //try to find
            // if(node.key == key)
                return node.value;
        //}

else
        return null;

    }

};

// // what is contract between hashcode and equals ?
// //ans. if we put hashcode on same object then it will give the same hascode always but if we put hashcode on different object then also same value "can" come
// // equals -> if obj1 == obj2 then hashcode will be same value

// //hascode might also use xor to have equal occurences

// //load factor = .75 or 75 percent

// //if hashmap is 75 percent filled then i have to resize 

// // next resize will be next power of 2

// // java 8 has internally list

// // treefy threshold is threshhold of list

// // if list of hashnode exceeds treefy threshold then it changes it to internlaly a balance binary tree becaue list if o(n) (so worst case wikll be o(log n ) due to treefy)

// //in jave hashcode >>> 16 will give less collision rather than mods