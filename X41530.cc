#include <iostream>
#include <vector>
using namespace std;

using VI= vector<int>;
using VVI=vector<VI>;
using VB=vector<bool>;

VVI g;
VB v;
int n, m;

bool subsearch(int x,int xa) {
    if (not v[x]) {
        v[x]=true;
        for (int i=0; i<g[x].size(); i++) {
            if (g[x][i]!=xa) {
            bool b=subsearch(g[x][i],x);
            if (b) return true;
            }
        }
        return false;
    }

    else return true;
}

void bosc() {
    int a=0;
    for (int i=0; i<n; i++) {
        if (not v[i]) {
            bool circle=subsearch(i,i);
            if (circle) {
                cout << "no" << endl;
                return;
            }
            ++a;
        }
    }
    cout << a << endl;
}

int main() {
    while (cin >> n >> m) {
        g=VVI(n);
        v=VB(n,false);
        for (int i=0; i<m; i++) {
            int x,y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);

        }
        bosc();
    }
}
