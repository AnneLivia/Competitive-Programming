#include <iostream>
#include <ctime>
#include <cstdlib>
#define TAM 10

/*
    Name: Anne Livia
    Binary search is a more specific searching algorithm
    it searches for a specific element in a sorted array by
    dividing repeatedly the search in halves.
    Complexity of this algorithm is O(log n)
    Algorithm:
    check if a number is equal to the middle element
    if it is then:
        return the mid index
    else
        if the number is greater then the middle element, then:
            the begin of the array now is going to start from middle + 1
        else
            the end of  the array now is going to middle - 1
        end
    end
*/

using namespace std;

int binarySearch(int *v, int b, int e, int n) {
    if(b <= e) { // If b is less or equal the end
        int mid = (b + e) >> 1; // begin + end / 2
        // If the element is present at the middle
        if(v[mid] == n)
            return mid;
        // If the element in the middle is greater then the element, it means that the element is at the leftmost side
        if(v[mid] > n) {
            return binarySearch(v,b,mid-1,n); // Then the end will now be mid - 1
        } else {
            return binarySearch(v,mid + 1, e, n); // else the begin will be mid + 1
        }
    }
    return -1; // if this gets here, it means that the element does not exist
}

void print_array(int *v, int tam) {
    for ( int i = 0; i < tam; i++) {
        cout << " " << v[i];
    }
}

void insertion_sort(int *v, int tam) {
    int value, j;
    for ( int i = 1; i < tam; i++) {
        value = v[i];
        j = i - 1;
        while ( j >= 0 ) {
            if(value < v[j]) {
                v[j + 1] = v[j];
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = value;
    }
}

int main()
{
    srand(time(NULL));
    int v[TAM], n, pos;
    for ( int i = 0; i < TAM; i++) {
        v[i] = 1 + rand() % 1000;
    }

    print_array(v,TAM);
    cout << endl;
    insertion_sort(v,TAM);
    print_array(v,TAM);
    cout << "\n Search for a value: ";
    cin >> n;

    pos = binarySearch(v,0,TAM,n);

    if(pos != -1)
        cout << "\n The value " << n << " is in the " << pos + 1 << " position\n";
    else
        cout << "\n The value " << n << " was not found.\n";

    return 0;
}
