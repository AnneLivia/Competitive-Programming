#include <iostream>
#include <vector>
#include "hashtable.h"

using namespace std;

/*
    What is a hash table?
    Hash Table is a data structure that is made up of two distinct parts:
    An array and a hash function.
        The array is what holds the data, it's where our data will be stored
        and is the one that we are going to search through to find data,
        The hash function (Mapping Function) is responsible to decide where our data will be stored
        and how we are going to get it out of the array.
    A hash table is made up of sets of pairs: key and a value (k, v).
    The idea is that if I have the key to one set of data, I can find the value in another set of data
    The key is the index of the array, and the value is the data that lives at that index.
    >> he hash function is used to take an item as input, and calculate and return the key for
    where that item must be inserted in the hash table.
    One simple example, suppose that we have a table of size 3.
    One very simple way to calculate one key to store the data is
    to take the number of character from a string and divide it by the size of the table.
    Suppose we want to store three data:
        Cars, House and Site;
    we can now take the remainder of the division and insert those data there.
    Cars = 3 characters and 4 % 4 (size of the table) = 0
    House = 5 character and 5 % 4 (size of the table) = 1
    skyscraper = 10 character and 10 % 4 (size of the table) = 2
    >>> [Cars][House][skyscraper][]
    Suppose we would like to add another word to our hash bucket which is the name that we give to the slots of our table
    and that word is: cellphone.
    cellphone = 9 characters and 9 % 4 = 1;
    but 1 already have a data at the index 1.
    This is called COLLISION. and it's totally normal.
    A collision occurs when two elements are supposed to be inserted at the same place in a array ( at the same hash bucket).
    No hash function will always return a unique hash bucket value for every item that give it.

    Using a hash table we can look up and insert data at a constant time O(1).
    that can happens by only pass the element into the hash function, which is going to tell
    exactly what index in the array (hash bucket) to look in.
    The same doesn't happens for other data structures such as: queue, stack, array, linked list, which take linear time to search for an element.
    It also only takes constant time to insert or delete an item into a hash table, because we’re always going to lean on our hash function
    to determine where to add or remove something!

    Hash tables are not always the best tool for some jobs such as they're not great for finding ordered data.

    Advantages of hash table:
        - Great efficiency in the search operation
        - search time is practically independent of the number of keys stores in the table
        - simple implementation
    Disadvantages:
        - Large cost to retrieve elements ordered by the keys. in this case it's necessary to order the table.
        - worst case is O(N), and N is the size of the table: large number of collisions.
    Applications:
        Search elements in a data base
        cryptography: MD5 and family SHA (Secure Hash Algorithm)
        Implementation of the Compilers Symbols Table
        Secure Password storage: the password is not store in the servers, but it's hash function.
        Verification of data integrity and message authentication
    ...
*/

int main()
{
    /*
        It's good to chose a prime number to be the size of the hash table and
        avoid using a power of two number.
        a prime number reduces the probability of collisions, even if the hashing function
        is not that good.
        A power of two number improves the speed, but can increase the problems of collision if
        we are using a simple hash function.
        Why is prime number good for hashing function?
        If the data is random there's no need for a prime number, we can do a mod operation against
        any number and we will have the same number of collisions for each possible value of the modulus.
        But when data is not random, then strange things happen.
        Consider a numeric data is always multiple of 10.
        if we use mod 4 we find:
            10 mod 4 = 2
            20 mod 4 = 0
            30 mod 4 = 2
            40 mod 4 = 0
            50 mod 4 = 2
        ....
        so if the 3 possible values of the modulus (0,1,2,3) only 0 and 2 will have collisions, and that's bad.
        if we use a prime number like 7 (a prime number only has 2 values that divisible by it), so the probability to
        get collision is lesser than when we use a power of two.

            10 mod 7 = 3
            20 mod 7 = 6
            30 mod 7 = 2
            40 mod 7 = 4
            50 mod 7 = 1
        ....
        There are some patterns that we must be aware, like in this example the keys are multiple of 5, so, suppose we use 5
        although 5 is a prime number, it's not a good choice here. This means that we must choose a prime number that doesn't divide
        our key.
            10 mod 5 = 0
            20 mod 5 = 0
            30 mod 5 = 0
            40 mod 5 = 0
            50 mod 5 = 0
        ...
        So the reason prime numbers are used is to neutralize the effect of patterns in the keys in the distribution of collisions of a
        hash function.
    */
    // creating hashTable
    Hash *hashTable = createHashTable(1024);

    // inserting elements in order (Name, job, company, age, id and salary)
    insert_WithoutCollision(hashTable, {"XX", "AA", "BB", 22, 101, 105000});
    insert_WithoutCollision(hashTable, {"CX", "CC", "BB", 23, 105, 140000});
    insert_WithoutCollision(hashTable, {"DX", "DA", "WW", 26, 102, 200000});

    Worker w;
    if(search_WithoutCollision(hashTable, 101, w))
        cout << "Worker: " << w.name << " was found\n";
    else
        cout << "Don't work\n";

    insert_OpenningAddressing(hashTable, {"TD", "KK", "XX", 25, 1331, 125000});
    insert_OpenningAddressing(hashTable, {"DD", "KK", "XX", 24, 111, 125000});
    insert_OpenningAddressing(hashTable, {"XL", "KK", "XX", 25, 141, 125000});

    if(search_OpenningAddressing(hashTable, 111, w))
        cout << "Worker: " << w.name << " was found\n";
    else
        cout << "Don't work\n";

    // Showing elements
    showData(hashTable);

    // destroying hashTable
    freeHashTable(hashTable);
    return 0;
}
