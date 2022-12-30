#include <iostream>
#include <map>
using namespace std;

using P = pair<string,string>;

void imprimir (const map<string, string>& m) {
    cout << m.size() << endl;
    for ( P p: m) cout << p.first << ' ' << p.second << endl;
}

int main() {
    string command;
    map<string,string> g;
    while (cin >> command) {
        if (command=="affair") {
            string s1, s2; cin >> s1 >> s2;
            if(g.find(s1)!=g.end() and g[s1]!="")g[g[s1]]="";
            if(g.find(s2)!=g.end() and g[s2]!="")g[g[s2]]="";
            g[s1]=s2;
            g[s2]=s1;
        }
        else {
            cout << "COUPLES:"<<endl;
            for (P p:g) {
                if(p.second!="" and p.first<p.second)
                    cout << p.first << ' ' << p.second << endl;
            }
            cout << "ALONE:"<<endl;
            for(P p: g) {
                if(p.second=="") cout << p.first << endl;
            }
            cout << "----------"<<endl;
        }
//          imprimir(g);
    }
}
