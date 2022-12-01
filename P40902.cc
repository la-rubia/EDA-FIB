#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    string name;
    string command;

    while (cin >> name >> command) {
        if (command=="enters") {
                if (m.find(name)!=m.end()) {
                    cout << name << " is already in the casino" << endl;
                }
                else {
                    m.insert(make_pair(name,0));
                }
        }
        else if (command=="wins") {
            int number; cin >> number;
            if (m.find(name)!=m.end()) {
                // está dentro del casino
                m[name]=m[name]+number;
            }
            else cout << name << " is not in the casino"<< endl;

        }
        else {
            if (m.find(name)!=m.end()) {
                // está dentro de casino
                auto it = m.find(name);
                int value = it->second;
                cout << name << " has won " << value << endl;
                m.erase(it);
            }
            else cout << name << " is not in the casino" << endl;
        }
    }

    cout << "----------" << endl;


    for (auto it = m.begin(); it!=m.end(); it++) {
        cout << it-> first << " is winning " << it -> second << endl;
    }
}
