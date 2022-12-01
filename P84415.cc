#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> m;
    string command;
    map<string,int> :: iterator it;
    while (cin >> command) {
        if (command == "minimum?") {
            if (m.begin()!=m.end()) {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite minimum" << endl;

        }
        else if (command == "store") {
            string w; cin >> w;
            it = m.find(w);
            if (it==m.end()) m.insert(make_pair(w,1));
            else m[w]++;
        }
        else if (command == "delete") {
            string w; cin >> w;
            it = m.find(w);
            if (it!=m.end()) {
                if (it->second>1) m[w]--;
                else if (it->second == 1)  m.erase(w);
            }


        }
        else {

            if (m.begin()!=m.end()) {
                it = m.end(); it--;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite maximum" << endl;
        }
    }
}
