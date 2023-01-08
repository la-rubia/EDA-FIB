#include <iostream>
#include <map>
using namespace std;

using P = pair<string,int>;

int n;

void gestionar(string y, map<string,int>& m) {
    if(m.end()==m.find(y)) {
        m[y]++;
        n++;
    }
    else {
        int x = m[y];
        int n1 = n+1;
        int x1 = x+1;
//         cout << "actual: " << x << ' ' << n << endl;
//         cout << "seria: " << x1 << ' ' << n1 << endl;
//         cout << x1 << "<=" << n1-x1 << endl;
        if(x1<=n1-x1) {
            m[y]++;
            n++;
        }
    }
}

void read_map(const map<string,int>& m) {
    for(P p: m) cout << p.first << ' ' << p.second << endl;
}


int main() {
    while(cin >> n) {
        map<string,int> m;
        for(int i=0; i<n; i++) {
            string x; cin >> x;
            m[x]++;
        }
//         read_map(m);
        int j; cin >> j;
        for(int i=0; i<j; i++) {
            string y; cin >> y;
            gestionar(y,m);
//             read_map(m);
        }
        read_map(m);
        cout << "--------------------" << endl;
    }
}
