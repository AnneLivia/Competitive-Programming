#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Structure with id and number of medals
struct Country {
    int id, points;
    bool operator () (const Country& c) const { // Operator function to check equality with find method
        return c.id == id;
    }
};

bool compare(const Country& n1, const Country& n2) { // Function to use inside the sort method
    if(n1.points > n2.points)
        return true;
    else if(n1.points == n2.points) {
        if(n1.id < n2.id)
            return true;
    }
    return false;
}

int main()
{
    int np, nm, o, p, b;
    vector<Country>vet;
    Country aux = {0,0};
    vector<Country>::iterator it;
    cin >> np >> nm;
    vet.assign(np,aux);
    // Initializing each position of the vector with id from 1 to NP
    for ( int i = 0; i < np; i++) {
        aux.id = i + 1;
        aux.points = 0;
        vet[i] = aux;
    }

    while(nm--) {
        cin >> o >> p >> b;
        aux.id = o;
        aux.points = 0;
        it = find_if(vet.begin(), vet.end(), Country(aux)); // Find the id from o
        if(it != vet.end())
            it->points++; // In case it was found, increment by one
        aux.id = p;
        aux.points = 0;
        it = find_if(vet.begin(), vet.end(), Country(aux)); // Find the id from p
        if(it != vet.end())
            it->points++;  // In case it was found, increment by one
        aux.id = b;
        aux.points = 0;
        it = find_if(vet.begin(), vet.end(), Country(aux)); // Find the id from b
        if(it != vet.end())
            it->points++; // In case it was found, increment by one
    }

    sort(vet.begin(), vet.end(), compare); // Sorting vector
    for ( int i = 0; i < np; i++) {
        cout << vet[i].id << " "; // print it onto the screen
    }
    cout << endl;

    return 0;
}
