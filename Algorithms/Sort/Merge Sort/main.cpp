#include <iostream>

using namespace std;
/*
    Name: Anne Livia
    Divide and conquer algorithm, with complexity O(n log n)
    This algorithm divides an array in two halves, merges the two sorted halves.
    A merge function is used to merge the two halves
    The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r]
    are sorted and merges the two sorted sub-arrays into one
    Algorithm according to geeks for geeks:
    MergeSort(arr[], l,  r)
    If r > l
        1. Find the middle point to divide the array into two halves:
            middle m = (l+r)/2
        2. Call mergeSort for first half:
            Call mergeSort(arr, l, m)
        3. Call mergeSort for second half:
            Call mergeSort(arr, m+1, r)
        4. Merge the two halves sorted in step 2 and 3:
            Call merge(arr, l, m, r)
*/

void mergeArray(int arr[], int low, int middle, int high)
{

    int size1 = middle - low + 1; // size of first part if from low to middle
    int size2 =  high - middle; // size of second part is from middle to the high

    /* create temp arrays */
    int left[size1], right[size2];

    // Copy all part to an auxiliary array: left part
    for (int i = 0; i < size1; i++)
        left[i] = arr[low + i];
    // Copy all part to an auxiliary array: right part
    for (int i = 0; i < size2; i++)
        right[i] = arr[middle + 1 + i];


    int i = 0; // first index of the leftmost side array
    int j = 0; // first index of the rightmost side array
    int k = low; // part being altered in the array

    while (i < size1 && j < size2) { // While the i is less than the middle and the j is less than the size of the array
        if (left[i] <= right[j]) { // If the number on the left side is lesser than the one on the right side
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j]; // else, get the value on the right side
            j++;
        }
        k++;
    }

    // copy the rest of the left side into the array, if remaining...
    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // copy the rest of the right side into the array, if remaining...
    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high) { // While the array can be divided

        int middle = low + ((high - low) >> 1); // Find the middle and avoid overflow in this way

        // Sort first and second halves
        mergeSort(arr, low, middle); // Call function again now passing an array of size 0..middle
        mergeSort(arr, middle + 1, high); // When the function gets here, is because all possibles division from left side was achieved, then now the size of the array will be middle + 1 .. high

        mergeArray(arr, low, middle, high); // When there's possibility to merge the array, this function will be called
    }
}

void print(int *v, int t) {
    for ( int i = 0; i < t; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int vet[10] = {1,5,4,3,6,5,13,7,2,35};
    cout << "Before merge sort: \n";
    print(vet,10);
    mergeSort(vet,0,9);
    cout << "After merge sort: \n";
    print(vet,10);
    return 0;
}
