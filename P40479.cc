#include <iostream>
#include <vector>
using namespace std;

using VC = vector <char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VP=vector<pair<int,int>>;

int n, m;
VVC tab;
VVB v;

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m and tab[x][y]!='#';
}

void djs(int x, int y, char c) {
    if (not v[x][y] and tab[x][y]!='#') {
        tab[x][y]=c;
        v[x][y]=true;

        if (ok(x-1,y)) djs(x-1,y,c);
        if (ok(x+1,y)) djs(x+1,y,c);
        if (ok(x,y-1)) djs(x,y-1,c);
        if (ok(x,y+1)) djs(x,y+1,c);
    }
}

int main() {
    while (cin >> n >> m) {
        tab = VVC(n,VC(m));
        v = VVB(n, VB(m));
        VP pos;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> tab[i][j];
                if (tab[i][j]!='#' and tab[i][j]!='.') pos.push_back({i,j});
            }
        }

        for (int i=0; i<pos.size(); i++) {
            djs(pos[i].first, pos[i].second, tab[pos[i].first][pos[i].second]);
        }

         for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << tab[i][j];
            }
            cout << endl;
    }
    cout << endl;
}
}
