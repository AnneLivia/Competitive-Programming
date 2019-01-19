#include <iostream>
#include <map>

using namespace std;

int main()
{

    map<string,string>natalMessage;
    natalMessage.insert(make_pair("brasil","Feliz Natal!"));
    natalMessage.insert(make_pair("alemanha","Frohliche Weihnachten!"));
    natalMessage.insert(make_pair("austria","Frohe Weihnacht!"));
    natalMessage.insert(make_pair("coreia","Chuk Sung Tan!"));
    natalMessage.insert(make_pair("japao","Merii Kurisumasu!"));
    natalMessage.insert(make_pair("grecia","Kala Christougena!"));
    natalMessage.insert(make_pair("espanha","Feliz Navidad!"));
    natalMessage.insert(make_pair("marrocos","Milad Mubarak!"));
    natalMessage.insert(make_pair("siria","Milad Mubarak!"));
    natalMessage.insert(make_pair("libia","Buon Natale!"));
    natalMessage.insert(make_pair("italia","Buon Natale!"));
    natalMessage.insert(make_pair("belgica","Zalig Kerstfeest!"));
    natalMessage.insert(make_pair("irlanda","Nollaig Shona Dhuit!"));
    natalMessage.insert(make_pair("canada","Merry Christmas!"));
    natalMessage.insert(make_pair("antardida","Merry Christmas!"));
    natalMessage.insert(make_pair("mexico","Feliz Navidad!"));
    natalMessage.insert(make_pair("chile","Feliz Navidad!"));
    natalMessage.insert(make_pair("argentina","Feliz Navidad!"));
    natalMessage.insert(make_pair("turquia","Mutlu Noeller"));
    natalMessage.insert(make_pair("suecia","God Jul!"));
    natalMessage.insert(make_pair("portugal","Feliz Natal!"));
    natalMessage.insert(make_pair("estados-unidos","Merry Christmas!"));
    natalMessage.insert(make_pair("inglaterra","Merry Christmas!"));
    natalMessage.insert(make_pair("australia","Merry Christmas!"));

    string nomeCountry;
    while(cin >> nomeCountry) {
        if(natalMessage.find(nomeCountry) != natalMessage.end())
            cout << natalMessage.at(nomeCountry) << endl;
        else
            cout << "--- NOT FOUND ---\n";
    }
    return 0;
}
