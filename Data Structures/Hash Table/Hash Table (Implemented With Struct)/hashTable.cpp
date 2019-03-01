#include "hashTable.h"

// Creating a hash table
Hash* createHashTable(int tableSize) {
    // allocating memory for the hash table
    Hash *hashTable = (Hash*) malloc(sizeof(Worker));
    // if it succeeded, then:
    if(hashTable != nullptr) {
        // assign the number of elements to 0, since there's no element yet
        hashTable->numberOfElements = 0;
        // assign the size of the table as tableSize
        hashTable->tableSize = tableSize;
        // Allocate memory of the array and assign to its position the null value
        hashTable->w = (Worker **)malloc(sizeof(Worker *) * tableSize);
        // if it succeeded
        if(hashTable->w != nullptr) {
            // assign to all elements, value null
            for (int i = 0; i < tableSize; i++) {
                hashTable->w[i] = nullptr;
            }
        } else {
            // doesn't succeeded, so free table and assign to it null
            free(hashTable);
            hashTable = nullptr;
        }
    }
    // Return the hash table
    return hashTable;
}

// Destruct the hash table: run through all the array and verify if exists an element to be deallocate.
void freeHashTable(Hash *hashTable) {
    // If hashTable exits
    if(hashTable != nullptr) {
        for (int i = 0; i < hashTable->tableSize; i++) {
            // If the data at the position i is different of null, it means
            // that there's a value assign to it
            if(hashTable->w[i] != nullptr) {
                // deallocate  it
                free(hashTable->w[i]);
            }
        }
        // deallocate the hashTable w
        free(hashTable->w);
        // deallocate the hashTable itself
        free(hashTable);
        // assign it to null to avoid dangling pointer
        hashTable = nullptr;
    }
}

// converting a string value to a key
int stringValue(string str) {
    int value = 7; // to initialize the sum
    for (int i = 0; i < (int)str.size(); i++) {
        // using the value 31 which some studies says that it is a good number to multiply
        value = 31 * value + (int)str[i];
    }
    return value;
}

/*
    Calculating key position:
    For insertion and search, it's necessary to calculate the position of the data
    in the hash bucket;
    Calculating the position of the key:
    Data
    A --------|                                |-> [B]
    B --------|==:> Keys            Position   |-> [ ]
    ----------------> Hashing Function ---->>> |-> [A]
    C --------|==:>                            |-> [C]
    D --------|                                |-> [D]

    Hashing function:
        - Allow to calculate one position from a key chosen from the data
        - it's extremely important for the good performance of the table
        - It's responsible for distribute the information in a equilibrated way
        through the hash table
    A hashing function must follow the following conditions:
        - Be simple and cheap to calculate
        - Guarantee that different values produces different positions (avoid collisions)
        - Generate a equilibrate distribution of data in the table, i.e. each position of the table
        has the same chance to receive a key (maximum distribution)
        - is deterministic. h(k)should always return the same value for a given k
    Important:
        The implementation of the hashing function depends upon the prior knowledge of the nature and
        domain of the key to be used to.
        Same problem as the prime number 5 be used for multiples of 5. Although is good to choose a prime
        number, in this case that won't be good.
    Some methods to be used in a hashing function:
        Division method
        Multiplication method
*/

/*
    Division method:
        - The division method is one way to create hash functions.
        It consist in calculate the remainder of the integer value that
        represents the element by the size of the table.
        - It's simple and straightforward
        The functions take the form:
            h(k) = k mod m;
*/
int keyUsingDivisionMethod(int key, int tableSize) {

    /*
        0x7FFFFFFF = 01111111111111111111111111111111 = 2147483647
        the maximum number a simple int can have.
        we do the & operation of the key with it to avoid the risk of getting
        an overflow and get a negative number.
    */

    return (key & 0x7FFFFFFF) % tableSize;
}

/*
    The multiplication method is another way to create hash functions.
    The functions take the form:
        h(k) = [m (kA mod 1)]
    Where for A: 0 < A < 1. This is used to multiply the value of the key that
    represents the element. following, the fractional part is multiplied by the size
    of the table to calculate the position of the element.
    Example, suppose we want to calculate the position of the key 123456
    the fractional constant A is 0.618
    the size of the table is 1024
    Steps we follow are:
        Multiply the A with the key
        result = 123456 * 0.618 = 76295.808
        Now we take the fractional part of the result
        result = 76295.808 - (int) 76295.808, which is 76295
        result is 0.808
        now we multiply the size of the table by the result
        position = (int)result(0.808) * tableSize(1024) = (827.392)
        position is 827

*/

int keyUsingMultiplicationMethod(int key, int tableSize) {
    float A = 0.6180339887; // constant A where: 0 < A < 1
    // multiply by A
    float fractionalPart = key * A;
    // the fractional part is taken
    fractionalPart = fractionalPart - (int)fractionalPart;
    // then return the size of the table multiplied by the resulting number
    return (int) (tableSize * fractionalPart);
}

/* insertion without collision treatment
   - Calculate the position of the keys in the array
   - allocate space for the data
   - store the data in the position calculated
*/
int insert_WithoutCollision(Hash *hashTable, Worker w) {
    // first verify if the hashTable exists and it's not full
    if(hashTable == nullptr || hashTable->tableSize == hashTable->numberOfElements)
        return 0;
    // using the id of the worker to get the position to store in the table
    int position = keyUsingDivisionMethod(w.id, hashTable->tableSize);
    // it could be the a string using the string function
    // int position = stringValue(w.name);
    // allocating the memory location for the data
    Worker* newWorker = new Worker();
    // Allocation not succeeded

    if(newWorker == nullptr)
        return 0;

    // I'm getting an error here
    *newWorker = w;

    // assign the newWorker to the calculated position
    hashTable->w[position] = newWorker;

    // increment the number of elements
    hashTable->numberOfElements++;
    // return 1 so that everything got right

    return 1;
}

int search_WithoutCollision(Hash *hashTable, int id, Worker& w) {
    // if hashTable is not empty and exist
    if(hashTable != nullptr && hashTable->numberOfElements != 0) {
        // calculate position
        int position = keyUsingDivisionMethod(id, hashTable->tableSize);
        // verify if there's a data at the position
        if(hashTable->w[position] != nullptr) {
            // return value
            w = *(hashTable->w[position]);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    // not error
    return 1;
}

/*
    Ways to avoid collision:
        We can use a universal Hashing which is a strategy to minimize the collisions in a hash table.
        universal hashing (in a randomized algorithm or data structure) refers to selecting a hash function
        at random from a family of hash functions with a certain mathematical property.
        We  choose in run time randomly a hash function to be used.
        To do this, we can construct a set of hash functions.
        There are a lot of ways to create a family, one example could be:
        Choose a prime number p such that the value in any key K to be inserted in the table
        is less than p and greater or equal to 0.
        p is greater than the table size
        Choose randomly 2 integer numbers, A and B.
            - 0 < a <= p
            - 0 <= b <= p
        We are use random numbers generated at the beginning of the application, so that
        the hash function is not deterministic
        h(k) _ {a,} = ((aK + b) % p) % TABLE_SIZE

    Depending on the size of the table and the values inserted, we can classify a hash function as:
        Imperfect:
            For two different keys, the output of the function can be the same position
            the collision of keys in the table is not extremely bad, it just something undesirable
            because it decrease the performance of the system
            Many hashTables uses other data structures to handle collisions
        Perfect:
            Guarantee that there won't be collisions of key inside the table, that is, different keys
            are going to produce different positions in the table.
            in the worst case the insertion and search is O(1)
            This hashing is utilized when collision is not tolerate
            It's refereed to a very specific type of application such as a set of reserved words from
            a programming language.
            In this case, we have prior knowledge of what the data that is.
        The creation of a hash table consists of two things:
            creating of a hashing function
            an approach to handle collisions
        Collision are in theory inevitable
    The some ways to handle collisions:
        - Open addressing or rehash:
            In case of a collision, it run thorough the table in search of an
            empty position.
            Avoid using linked list
            Some Advantages:
                The search is done in the table itself, which increases performance
            Some disadvantages:
                Insertion is O(N) when all elements are in collision
        - Separate Chaining
            It doesn't search for empty position
            Store in each position of the table the start of a dynamic linked list
            the collisions are store inside those linked list
            Advantages:
                Words case of insertion is O(1) if the list is not ordered
            Disadvantages:
                The search is done by traversing the list.
                memory complexity is big: pointers of lists are stored.
    ........
*/

/*
    Opening Address:
        There are three most used strategies:
            Linear probing:
                Try to spread the elements in a sequential way from the calculated
                position.
                Steps:
                    The first element I is inserted in the position obtained by the hash function:
                    second element (collision) is inserted at the position pos+1
                    third element (collision) is inserted at the position pos+2
                When the table gets full, the time complexity increases
            Quadratic Probing:
                try to spread the elements utilizing a second degree equation
                pos + (c1 * i) + (c2 * i^2)
                where pos is the position obtained by the hashing function
                i is the current try
                c1 and c2 are the coefficients of the equation
                Steps:
                    First element is inserted at the pos return by the hashing function
                    second element (collision) is inserted at pos + (c1 * 1) + (c2 * i^2)
                    third element  (collision) is inserted at pos + (c1 * 2) + (c2 * i^2)
                    ...
                All the keys that produces the same initial position in the table also produces
                the same position in the quadratic probing.
            double hashing:
                try to spread the element utilizing two hashing functions
                H1 + i + h2
                where:
                    h1 is used to calculate initial position
                    h2 is used to calculate dislocations according to the initial position in case
                    of a collision
                we only use the second function if it occurred a collision
                steps:
                    first element i = 0, is placed in the position obtained by the h1
                    second element in case of collision is placed at the position h1 + 1 + h2
                    third element in case of a collision is place at the position h1 + 2 + h2
                    ....
            it's necessary two different hashing functions and the second one cannot return 0 function
            a tip is to use the size of the table a little bit small and add up
    ....
*/

int linearProbing(int pos, int i, int tableSize) {
    // 0x7FFFFFFF to avoid overflow
    return ((pos + i) & 0x7FFFFFFF) % tableSize;
}

int quadraticProbing(int pos, int i, int tableSize) {
    // 0x7FFFFFFF to avoid overflow
    // applying the equation formula using random coefficients
    pos = pos + 2 * i + 5 * i * i;
    return ((pos + i) & 0x7FFFFFFF) % tableSize;
}

int doubleHashing(int h1, int key, int i, int tableSize) {
    // 0x7FFFFFFF to avoid overflow
    // h1 was obtained by another hashing function
    int h2 = keyUsingDivisionMethod(key, tableSize - 1) + 1;
    return ((h1 + i * h2)  & 0x7FFFFFFF) % tableSize;

}

int insert_OpenningAddressing(Hash *hashTable, Worker w) {
    // Verify if hashTable exists and if it's not empty
    if(hashTable == nullptr || hashTable->numberOfElements == 0)
        return 0;
    int key = w.id; // id is the key here
    int position, newPosision;
    // getting the position
    position = keyUsingDivisionMethod(key, hashTable->tableSize);
    // checking if there's collision
    for (int i = 0; i < hashTable->tableSize; i++) {
        // using linear probing strategy
        newPosision = linearProbing(position, i, hashTable->tableSize);
        // if it's an empty place, insert it there
        if(hashTable->w[newPosision] == nullptr) {
            Worker *newW = new Worker();
            // any memory was allocated
            if(newW == nullptr)
                return 0;
            // assign data to it
            *newW = w;
            // increment number of items
            hashTable->numberOfElements++;
            // insert element in the newPos of the table
            hashTable->w[newPosision] = newW;
            return 1; // success
        }
    }
    // error
    return 0;
}

int search_OpenningAddressing(Hash *hashTable, int id, Worker& w) {
    // calculate position of the key in the array
    // verify if there's data in the position and if the data is combined with the key
    // recalculate position while data are different from the key
    // return data
    // checking if hash exist
    if(hashTable == nullptr || hashTable->numberOfElements == 0)
        return 0;
    int position = keyUsingDivisionMethod(id, hashTable->tableSize);
    for (int i = 0; i < hashTable->tableSize; i++) {
        int newPosition = linearProbing(position, i, hashTable->tableSize);
        // element does not exist here
        if(hashTable->w[newPosition] == nullptr)
            return 0;
        if(hashTable->w[newPosition]->id == id) {
            w = *(hashTable->w[newPosition]);
            return 1; // element exist
        }
    }
    return 0; // element does not exist
}

// Function to show all the data in the table
void showData(Hash *hashTable) {
    for (int i = 0; i < hashTable->tableSize; i++) {
        if(hashTable->w[i] != nullptr) {
            cout << "Worker " << i << ":\n";
            cout << "Name: " << hashTable->w[i]->name << endl;
            cout << "Job: " << hashTable->w[i]->job << endl;
            cout << "Company: " << hashTable->w[i]->company << endl;
            cout << "Age: " << hashTable->w[i]->age << endl;
            cout << "Id: " << hashTable->w[i]->id << endl;
            cout << "Salary: " << hashTable->w[i]->salary << endl << endl;
        }
    }
}
