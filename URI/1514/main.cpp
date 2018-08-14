#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int npa, npe, n, cont, cont2, allSolve1, solveAll, allPsolved, caracCont;
    vector<vector<int>>v;
    while(cin >> npa >> npe && npa && npe) {
        solveAll = caracCont = allPsolved = allSolve1 = 0;
        v.assign(npa,vector<int>());
        for(int i = 0; i < npa; i++) {
            for(int j = 0; j < npe; j++) {
                cin >> n;
                v[i].push_back(n);
            }
        }
        vector<int>vet(npe);  // Will store if a i problem was solved or not

        for(int i = 0; i < npa; i++) {
            cont = 0;

            // Checking if everyone solved at least one problem
            if(find(v[i].begin(),v[i].end(),1) != v[i].end())
                allSolve1++;
            for(int j = 0; j < npe; j++) {
                // counting number of accepted problems from person i
                if(v[i][j] == 1) {
                    vet[j] = 1; // Storing problems that were solved at least one time
                    cont++;
                }


            }


            if(cont == npe) // checking if someone has solved all problems
                solveAll++;
        }

        for (int i = 0; i < npe; i++) {
            cont2 = 0;
            for(int j = 0; j < npa; j++) {
                // counting if any problem was solved by everyone
                if(v[j][i] == 1)
                    cont2++;
            }
            if(cont2 == npa) // if cont2 is equal to number of participants, then a specific question was solved by everyone
                allPsolved++;
        }

        // If there's at least one 0, not all question were solved
        if(!(find(vet.begin(),vet.end(),0) != vet.end()))
            caracCont++;
        if(solveAll == 0)
            caracCont++;
        if(allPsolved == 0)
            caracCont++;
        if(allSolve1 == npa)
            caracCont++;

        cout << caracCont << endl;
    }
    return 0;
}
