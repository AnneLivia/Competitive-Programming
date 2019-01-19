#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string inst1, atri, inst2;
    string aux1, aux2, last;
    bool issum;
    int n;
    map<string,int>va;
    while(cin >> inst1 >> atri) {
        getline(cin,inst2);
        issum = false;
        for ( int i = 0; i < (int)inst2.size(); i++) {
            if(inst2[i] == '+') {
                issum = true;
                break;
            }
        }
        inst2+=" "; aux1 = ""; aux2 = "";
        bool letter = false;
        if(issum) {
            bool firstExp = false;
            bool letter2 = false;
            for ( int i = 0; i < (int)inst2.size(); i++) {
                if(!firstExp && inst2[i] >= 'a' && inst2[i] <= 'z') {
                    letter = true;
                    aux1+=inst2[i];
                } else if (!firstExp && inst2[i] >= '0' && inst2[i] <= '9') {
                    letter = false;
                    aux1+=inst2[i];
                } else if (firstExp && inst2[i] >= 'a' && inst2[i] <= 'z') {
                    letter2 = true;
                    aux2+=inst2[i];
                } else if (firstExp && inst2[i] >= '0' && inst2[i] <= '9') {
                    letter2 = false;
                    aux2+=inst2[i];
                }
                if(inst2[i] == '+') {
                    firstExp = true;
                }
            }

            if(letter && letter2) { // Both letter
                if(va.find(aux1) != va.end() && va.find(aux2) != va.end()) {
                    if(va.find(inst1) != va.end()) {
                        va.at(inst1) = va.at(aux1) + va.at(aux2);
                    } else {
                        va.insert(make_pair(inst1,va.at(aux1) + va.at(aux2)));
                    }
                }
            } else if (letter && !letter2) {
                if(va.find(aux1) != va.end()) {
                    if(va.find(inst1) != va.end()) {
                        va.at(inst1) = va.at(aux1) + stoi(aux2);
                    } else {
                        va.insert(make_pair(inst1,va.at(aux1) + stoi(aux2)));
                    }
                }
            } else if (!letter && letter2) {
                if(va.find(aux2) != va.end()) {
                    if(va.find(inst1) != va.end()) {
                        va.at(inst1) = stoi(aux1) + va.at(aux2);
                    } else {
                        va.insert(make_pair(inst1,stoi(aux1) + va.at(aux2)));
                    }
                }
            } else {
                if(va.find(inst1) != va.end()) {
                    va.at(inst1) = stoi(aux1) + stoi(aux2);
                } else {
                    va.insert(make_pair(inst1,stoi(aux1) + stoi(aux2)));
                }
            }
        } else {
            for ( int i = 0; i < (int)inst2.size(); i++) {
                if(inst2[i] >= 'a' && inst2[i] <= 'z') {
                    aux1+=inst2[i];
                    letter = true;
                } else if (inst2[i] >= '0' && inst2[i] <= '9') {
                    aux1+=inst2[i];
                    letter = false;
                }
            }
            if(letter) {
                if(va.find(aux1) != va.end()) {
                    if(va.find(inst1) != va.end()) {
                        va.at(inst1) = va.at(aux1);
                    } else {
                        va.insert(make_pair(inst1,va.at(aux1)));
                    }
                }
            } else {
                if(va.find(inst1) != va.end()) {
                    va.at(inst1) = stoi(aux1);
                } else {
                    va.insert(make_pair(inst1,stoi(aux1)));
                }
            }
        }
        last = inst1;
    }
    cout << va.at(last) << endl;
    return 0;
}
