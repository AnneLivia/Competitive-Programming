#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
#include <cstdlib>

using namespace std;

// Data to be store in the hash table
struct Worker {
    string name, job, company;
    int age, id;
    float salary;
};

// Hash definition
struct Hash {
    // Pointer to Pointer, one pointer creates a array and the other one is used to store the address of the element
    // The hash table is going to store the address of the structure that contains the data of some worker and not the data itself
    // this kind of approach has as an objective to avoid the excessive waste of memory.
    // As the elements are inserted in the table, we can do the allocation of that specific element
    Worker **w;
    // Size of the table and number of elements
    int tableSize, numberOfElements;
};

void showData(Hash *hashTable);
// Function to create table with some specific size
Hash* createHashTable(int tableSize);
// function to free hashTable
void freeHashTable(Hash *hashTable);
// function to convert string to value
int stringValue(string str);
// function to calculate the exactly slot to add an element using division method
int keyUsingDivisionMethod(int key, int tableSize);
// Multiplication method to get a slot
int keyUsingMultiplicationMethod(int key, int tableSize);
// insert and search without collision
int insert_WithoutCollision(Hash *hashTable, Worker w);
int search_WithoutCollision(Hash *hashTable, int id, Worker& w);
// insert and search using open Addressing
// Open addressing, or closed hashing, is a method of collision resolution in hash tables.
int insert_OpenningAddressing(Hash *hashTable, Worker w);
int search_OpenningAddressing(Hash *hashTable, int id, Worker& w);
// opening addressing strategies:
int linearProbing(int pos, int i, int tableSize);
int quadraticProbing(int pos, int i, int tableSize);
int doubleHashing(int h1, int key, int i, int tableSize);
#endif
