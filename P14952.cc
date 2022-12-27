#include <iostream>
#include <set>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector <vector<int>>;
int n,m;

VVI g;

int main() {
    while (cin >> n >> m) {
    g=VVI(n);
    VI grau(n);
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        grau[y]++;
    }

    set<int> s;
    for (int i=0; i<n; i++) {
        if (grau[i]==0) s.insert(i);
    }

    bool first=false;
    while (not s.empty()) {
        auto it=s.begin();  int x=*it;  s.erase(it);
        if (not first) {
            cout << x;
            first=true;
        }
        else cout <<' '<< x;
        for (int i=0; i<g[x].size(); i++) {
            int y=g[x][i];
            if (--grau[y]==0) s.insert(y);
        }
    }

    cout << endl;
    }
}
