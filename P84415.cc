#include <iostream>
#include <map>
using namespace std;

int main() {
    string command;
    map<string,int> m;
    while (cin >> command) {
        if (command=="minimum?") {
            if (m.size()==0) cout << "indefinite minimum"<<endl;
            else {
                auto it = m.begin();
                cout << "minimum: " << it->first << ", "<<it->second << " time(s)"<<endl;
            }
        }
        else if (command=="maximum?") {
            if (m.size()==0) cout << "indefinite maximum"<<endl;
            else {
                auto it=m.end(); it--;
                 cout << "maximum: " << it->first << ", "<<it->second << " time(s)"<<endl;
            }
        }
        else if (command=="delete") {
            string p; cin >> p;
            if(m[p]<=1) m.erase(p);
            else m[p]--;
        }
        else {
            string p; cin >> p;
            if (m.end()==m.find(p)) m.insert({p,1});
            else m[p]++;
        }
    }
}
