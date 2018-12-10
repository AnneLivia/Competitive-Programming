#include <iostream>
#include <cstdio>

using namespace std;

/*
    Quick sort: O ( n log n )
    Divide and conquer
    one element is chosen as a pivot
    it partitions the given array around the pivot
    values lesser than pivot, go to the left, greater go to right
    Disadvantage: how to choose a pivot?
    Different versions:
        always pick first element as pivot
        always pick last element as pivot
        pick random element as pivot
        pick median as pivot
    The algorithm is stable with some modifications
*/

// Implementation 1
int partition1(int *vet, int first_index, int last_index);
void quick_sort1(int *vet, int first_index, int last_index);

// Implementation 2 from geeks for geeks
int partition2(int *vet, int first_index, int last_index);
void quick_sort2(int *vet, int first_index, int last_index);

int main() {
    int v[5] = {7,5,32,6,2};

    for (int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    quick_sort2(v,0,4);

    for (int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

// Implementation 1
int partition1(int *vet, int first_index, int last_index) {
    int left = first_index, right = last_index;

    int pivot = vet[first_index]; // Getting the first index as a pivot

    // While the left is not the same or above as right the loop will run
    while(left < right) {
        while(vet[left] <= pivot) // When find a value grater than pivot it will stop
            left++;
        while(vet[right] > pivot) // When find a value smaller than pivot it will stop
            right--;
        if(left < right) // if the index from left is smaller than right, then swap them.
            swap(vet[right], vet[left]);
    }
    swap(vet[right], vet[first_index]); // Right will stop at the minimum position to then swap it with the pivot
    return right;
}

void quick_sort1(int *vet, int first_index, int last_index) {
    if(last_index > first_index) { // Base case: last index must be greater than first index
        // Divide the array into two partitions
        int pivot = partition1(vet, first_index, last_index);
        // Calls quick sort for those two partition
        quick_sort1(vet, first_index, pivot - 1);
        quick_sort1(vet, pivot + 1, last_index);
    }
}


// Implementation 2 from geeks for geeks
int partition2(int *vet, int first_index, int last_index) {
    int i = first_index - 1;
    int pivot = vet[last_index];

    for (int j = first_index; j < last_index; j++) {
        // All smaller number will be placed before pivot
        if(vet[j] <= pivot) {
            i++;
            swap(vet[i],vet[j]);
        }
    }
    swap(vet[last_index],vet[i + 1]);
    return i + 1;
}

void quick_sort2(int *vet, int first_index, int last_index) {
    if(first_index < last_index) { // Base case

        int pivot = partition2(vet, first_index, last_index);

        quick_sort2(vet, first_index, pivot - 1); // Before pivot
        quick_sort2(vet, pivot + 1, last_index);  // After pivot
    }
}

