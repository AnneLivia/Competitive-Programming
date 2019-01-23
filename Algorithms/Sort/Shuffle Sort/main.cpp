#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


/*
    Shuffle is done to generate random permutation in a array
*/

// Knuth shuffle (Fisher-Yates shuffle Algorithm)
// An equivalent version which shuffles the array in the opposite direction (from lowest index to highest)
void shuffle(vector<int>&v) {
    int n = (int)v.size();
    for (int i = 0; i < n; i++) {
        int random = rand() % (i + 1); // random number between 0 and i
        swap(v[i],v[random]);
    }
}

// (Fisher-Yates shuffle Algorithm) by Richard Durstenfeld and popularized by Donald Knuth
// -- To shuffle an array a of n elements (indexes 0..n-1):
// The idea is to start a loop from the end of the array to 0, and then
// get a randomly selected element from the whole array, including the last one
// and swap them. this process is going to be repeated until it reaches the first element

void shuffleFisherYates(vector<int>&v) {
    for (int i = (int)v.size() - 1; i >= 1; i--) {
        int random = rand() % (i + 1); // random from 0 to i (last element - 1, last element - 2, etc.) (n,N]
        swap(v[i],v[random]); // swap them
    }
}

// Shuffle deck of cards (war story (on line poker)) at planetPoker.com
// This algorithm is not good
void shuffleCards(vector<int>&v) {
    for (int i  = 0; i < (int)v.size(); i++) {
        int r = 1 + rand() % (int)v.size() - 1; // getting a random position from 1 to 51
        swap(v[i],v[r]); // Swapping current card in I position with the random one
    }
}

ostream& operator << (ostream& stream, vector<int>&v) {
    for(auto i : v)
        stream << i << " ";
    stream << endl;
    return stream;
}

int main()
{
    srand(time(nullptr));
    vector<int>v{1,2,55,3,2,5,6};
    cout << v << endl;
    shuffleFisherYates(v);
    cout << v << endl;
    return 0;
}
