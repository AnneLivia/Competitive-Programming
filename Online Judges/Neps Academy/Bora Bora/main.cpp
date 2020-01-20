#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Card {
    int number;
    char naipe;
};

struct Player {
    int id, totalCard;
    vector<Card>c;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;

    vector<Player> players;
    vector<Card> deck;

   while( cin >> p >> m >> n && p && m && n) {

        players.assign(p, {0, m, vector<Card>()});
        deck.assign(n, {0,'0'});

        // info about deck
        for (int i = 0; i < n; i++) {
            cin >> deck[i].number >> deck[i].naipe;
        }

        int topDeck = 0, pp = 1;
        // m cards for p
        while(pp <= p) {
            players[pp - 1].id = pp;
            //cout << "Player: " << pp << endl;
            //cout << "Before: topdeck: " << topDeck << " - pp * m: " << pp * m << ", pp: " << pp << ", p * m: " << p*m << endl;
            if(topDeck < pp * m) {
                players[pp - 1].c.push_back(deck[topDeck++]);
            } else {
                pp++;
            }
        }

        /*
            for (int i = 0; i < p; i++) {
            cout << "Player  "  << players[i].id << endl;
            for(int j = 0; j < players[i].c.size(); j++) {
                cout << players[i].c[j].naipe << " - " << players[i].c[j].number << ", ";
            }
            cout << endl;
        }*/
        // obtaining discarded card
        Card descarte = deck[topDeck++];

        // clockwise = 1,  counterclockwise= -1
        int sentido = descarte.number == 12 ? -1 : 1, playerToPlay = 0, playerPenalty = 0;

        // where game starts
        while(true) {
            /*
            cout << "Player  "  << players[playerToPlay].id << ", Player Penalty: " << playerPenalty + 1 << " - " << sentido << endl;
            for(int j = 0; j < players[playerToPlay].c.size(); j++) {
                cout << players[playerToPlay].c[j].naipe << " - " << players[playerToPlay].c[j].number << ", ";
            }
            cout << "\nPilha de descarte: " << descarte.naipe <<" - " << descarte.number << endl;
            */
            bool discarded = false;
            // check rules for discarded card
            if (descarte.number == 7 && playerToPlay == playerPenalty) {
                // must take two cards from deck
                if(topDeck < n) {
                    players[playerToPlay].c.push_back(deck[topDeck++]);
                    players[playerToPlay].totalCard+=1;
                }
                if(topDeck < n) {
                    players[playerToPlay].c.push_back(deck[topDeck++]);
                    players[playerToPlay].totalCard+=1;
                }
            } else if (descarte.number == 1 && playerToPlay == playerPenalty) {
                // must take one cards from deck
                if(topDeck < n) {
                    players[playerToPlay].c.push_back(deck[topDeck++]);
                    players[playerToPlay].totalCard+=1;
                }
            } else if ((descarte.number != 11 && playerToPlay == playerPenalty) || (playerToPlay != playerPenalty)) {
                // check which one can be discarded (same suit or same number)
                int posCard = -1, number = 0;
                char naipe = 'A';
                for (int i = 0; i < (int)players[playerToPlay].c.size(); i++) {
                    if((players[playerToPlay].c[i].number == descarte.number ||
                       players[playerToPlay].c[i].naipe == descarte.naipe) &&
                       (players[playerToPlay].c[i].naipe != '1' &&
                       players[playerToPlay].c[i].number != 0)) {
                        if(players[playerToPlay].c[i].number > number ||
                           (players[playerToPlay].c[i].number == number && players[playerToPlay].c[i].naipe > naipe)) {
                            number = players[playerToPlay].c[i].number;
                            naipe = players[playerToPlay].c[i].naipe;
                            posCard = i;
                        }
                    }
                }

                if(posCard != -1) {
                      descarte = {players[playerToPlay].c[posCard].number, players[playerToPlay].c[posCard].naipe};
                       // removing it from his hand
                       players[playerToPlay].c[posCard] = {0,'1'};
                       players[playerToPlay].totalCard--;
                       discarded = true;
                }

                if(!discarded) {
                    if(topDeck < n) {
                        // get one more from the deck
                        if(deck[topDeck].number == descarte.number || deck[topDeck].naipe == descarte.naipe) {
                            descarte = deck[topDeck];
                            discarded = true;
                        } else {
                            players[playerToPlay].c.push_back(deck[topDeck]);
                            players[playerToPlay].totalCard++;
                        }
                        //cout << "Player " << playerToPlay << " pegou " << deck[topDeck].number << " - " << deck[topDeck].naipe << endl << endl;
                        topDeck++;
                    }
                }
            }

            playerPenalty = -1;

            if(discarded && players[playerToPlay].totalCard == 0) {
                cout << players[playerToPlay].id << endl;
                break;
            }

            if(descarte.number == 12 && discarded) {
                sentido = (sentido == -1) ? 1 : -1;
            }

            int pr = playerToPlay;
            // pass to other player
            playerToPlay+=sentido;
            if(playerToPlay < 0) {
                playerToPlay = p - 1;
            } else if (playerToPlay >= p) {
                playerToPlay = 0;
            }

            if((descarte.number == 1 || descarte.number == 7 || descarte.number == 11 ) && discarded) {
                playerPenalty = playerToPlay; // indicating who is going to receive penalty
            }

            /*
            cout << "\nPlayer " << pr + 1 << " descartou: " << descarte.naipe <<" - " << descarte.number << "\n\n";

            cout << "Deck: \n";
            for (int i = topDeck; i < n; i++) {
                cout << deck[i].number << ", " << deck[i].naipe << endl;
            }
            cout << endl << endl;
            */
        }
   }
    return 0;
}
