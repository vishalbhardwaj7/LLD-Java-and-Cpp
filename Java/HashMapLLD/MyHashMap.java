// package HashMapLLD;

// public class MyHashMap<K,V> {
//     private static final int INITIAL_SIZE = 1<<4; // 16
//     private static final int MAXIMUM_CAPACITY = 1<<30; 
//     //why max capacity of hashmap is 1<<30 ?
//     //we know max bits is 32 in int
//     //we write -2^31 to 2^31-1 
//     //one bit is sign bit
//     //hasmap size if 2^x
//     //can we take it 2^31
//     //no it is 2^31-1
//     //so as it is one less so it is ideal to have it as 2^30

//     public Entry[] hashTable;

//     public MyHashMap(){
//         hashTable = new Entry[INITIAL_SIZE];
//     }

//     final int tableSizeFor(int cap){
//         int n = cap-1;
//         n|=n>>>1;
//         n|=n>>>2;
//         n|=n>>>4;
//         n|=n>>>8;
//         n|=n>>>16;
//         return (n<0)?1:(n>=MAXIMUM_CAPACITY)?MAXIMUM_CAPACITY:n+1;
//     }
//     //lets say we were given tableSizeFor(7)
//     //so will return 8 as it is next greater power of 2
//     // how does this code work?
//     // >>> unsigned right shift operator
//     // for positive numbers >> and >>> behaves same
//     // >> does not work on sign bit
//     // >>> consider sign bit also
//     // lets say we were given 7
//     // _ 32 16 8 4 2 1 
//     // cap - 1 = 7
//     // why we do -1 ? 
//     // it will turn the MSB as 0 always
//     // 7 is 111
//     // 6 is 011
//     // lets take 15 as 7 is confusing
//     // next greater is 16
//     // do -1
//     // 14 is written as 1 1 1 0
//     // now we will try to put all the other bits shift by one place and "or" it so that all other bits become 1 1 1 1 1
//     //at the end i will do +1 to make it from 1 1 1 1 1 1 1 to 1 (no. of 1s i did)
//     //why we not doing it 30 times but 2 4 8 ..................
//     // we have 1 0 0 0 
//     // now it becomes 1 1 0 0
//     // then 1 1 1 1 because now i will shift two bits
//     public MyHashMap(int capacity){
//         int tableSize=tableSizeFor(capacity);
//         hashTable=new Entry[tableSize];
//     }

//     class Entry<K,V>{//basically a node
//         public K key;
//         public V value;
//         public Entry next;

//         Entry(K k, V v){
//             key =k;
//             value = v;
//         }
//     }

//     public void put(K key, V value){
//         int hashCode = key.hashCode()%hashTable.length;//compute hashcode of key % to keep it in bounds of length of hashtable
//         //lets say 3 came as hashcode
//         Entry node = hashTable[hashCode];

//         if(node == null){
//             Entry newNode = new Entry(key,value);
//             hashTable[hashCode]=newNode;
//         }
//         else{//this is a collision case
//             Entry previousNode=  node;
//             while(node != null){
//                 if(node.key == key){// if value matches
//                     node.value=value;
//                     return;
//                 }
//                 previousNode = node;//searching for last ndoe
//                 node=node.next;
//             }
//             Entry newNode = new Entry(key,value);
//             previousNode.next=newNode;
//         }

//     }

//     public V get(K key){
//         int hashCode = key.hashCode()%hashTable.length;
//         Entry node = hashTable[hashCode];

//         while(node != null){
//             if(node.key.equals(key)){
//                 return (V) node.value;
//             }
//             node = node.next;
//         }
//         return null;//not found
//     }
// }
// //Questions
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