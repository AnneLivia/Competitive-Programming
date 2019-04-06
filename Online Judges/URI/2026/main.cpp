#include <iostream>
#include <vector>

using namespace std;

vector<int> packet, weight;

int branchMaximum(const int& maximumWeight) {
    int nPacket = (int)packet.size();
    vector<vector<int> > pd (2, vector<int>(maximumWeight + 1, 0));
    int k = 1;
    for (int i = 1; i < nPacket + 1; i++) {
        for (int j = 0; j < maximumWeight + 1; j++) {
            pd[k][j] = pd[!k][j]; // getting the one above it
            if(j - weight[i - 1] >= 0) {
                pd[k][j] = max(pd[!k][j], pd[!k][j - weight[i - 1]] + packet[i - 1]);
            }
        }
        k = !k;
    }
    return pd[!k][maximumWeight];
}

int main()
{
    int branch, maximumWeight, nPackets, t = 1;
    cin >> branch;
    while(branch--) {
        cin >> nPackets >> maximumWeight;
        packet.assign(nPackets, 0);
        weight.assign(nPackets, 0);
        for(int i = 0; i < nPackets; i++) {
            cin >> packet[i] >> weight[i];
        }
        cout << "Galho " << t++ << ":\n";
        cout << "Numero total de enfeites: " << branchMaximum(maximumWeight) << endl << endl;
    }
    return 0;
}
