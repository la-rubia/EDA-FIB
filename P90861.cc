#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int n;

void escribir(const vector<queue<string>>& v) {
    for(int i=0; i<n; i++) {
        queue<string> p = v[i];
        cout << "cua "<< i+1<<':';
        while (not p.empty()) {
            cout <<' '<< p.front();
            p.pop();

        }
        cout <<endl;
    }
}

int main() {
    cin >> n;
    string line;
    getline(cin,line); // PQ???
    vector<queue<string>> V(n);
    for(int i=0; i<n; i++) {
        string s;
        getline(cin,s);
        istringstream ss(s);
        string nom;
        while(ss>>nom) V[i].push(nom);
    }

//     escribir(V);

    string command;
    vector<string> sortides;
    while(cin >> command) {
        if(command=="SURT") {
            int x; cin >> x;
            if(x>0 and x<=n) {
                if(not V[x-1].empty()) {
                    sortides.push_back(V[x-1].front());
                    V[x-1].pop();
                }
            }
        }
        else {
            string s; int x;
            cin >> s >> x;
            if(x>0 and x<=n) {
                V[x-1].push(s);
            }

        }
    }
    cout << "SORTIDES"<< endl;
    cout << "--------"<<endl;
    for(string s: sortides) cout << s << endl;
    cout << endl;
    cout << "CONTINGUTS FINALS"<< endl;
    cout << "-----------------"<<endl;
    escribir(V);

}
