#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct jugador {
    string name;
    int points;
};

bool cmp ( jugador a, jugador b) {
    if (a.points!=b.points) return a.points>b.points;
    return a.name<b.name;
}

int main() {
    string i;
    unordered_map<string,pair<int,bool>> game;
    while (cin >> i) {
        if (i == "LOGIN") {
            string j; cin >> j;
            auto it = game.find(j);
            if (it==game.end()) {
                game.insert(make_pair(j,make_pair(1200,true)));
            }
            else game[j].second = true;
        }
        else if (i == "LOGOUT") {
            string j; cin >> j;
            auto it = game.find(j);
            if ( it!= game.end()) game[j].second = false;
        }
        else if (i == "PLAY") {
            string j1; string j2; cin >> j1 >> j2;
            auto it1 = game.find(j1);

            if (it1!=game.end() and ((it1->second).second)) {
                auto it2 = game.find(j2);
                if (it2!=game.end() and ((it2->second).second)) {
                    (it1->second).first+=10;
                    if ((it2->second).first>=1210)(it2->second).first-=10;
                }
                else cout << "player(s) not connected" << endl;
            }
            else cout << "player(s) not connected"<<endl;

        }
        else {
            string j; cin >> j;
            auto it = game.find(j);
            cout << j << ' ' << (it->second).first << endl;
        }
    }
    if (not game.empty())cout << endl;
    cout << "RANKING" << endl;
    vector<jugador> vj;
    for (auto x: game) {
        jugador j;
        j.name =x.first;
        j.points = (x.second).first;
        vj.push_back(j);
    }
    sort (vj.begin(), vj.end(), cmp);
    for (auto i = vj.begin(); i!=vj.end(); i++) cout << i->name << ' ' << i->points << endl;

}
