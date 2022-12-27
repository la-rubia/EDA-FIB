#include <iostream>
#include <vector>
using namespace std;

int n,m;
using VC=vector<char>;
using VVC=vector<VC>;
using VB=vector<bool>;
using VVB=vector<VB>;

bool ok(int x, int y, const VVC& mapa) {
    return x>=0 and x<n and y>=0 and y<m and mapa[x][y]!='X';
}

bool dfs(int x, int y, const VVC& mapa, VVB& visit) {
    bool b1=false,b2=false,b3=false,b4=false;
//     cout << x << ' ' << y  << "Aún no ha cascado" << endl;
    if (ok(x,y,mapa) and not visit[x][y]) {
//         cout << x << ' ' << y << "  " << mapa[x][y] << endl;
        visit[x][y]=true;
        if (mapa[x][y]=='t') return true;
        if (ok(x-1,y,mapa)) {
//             cout << "HA pasado 1" << endl;
            b1=dfs(x-1,y,mapa,visit);
        }

        if (ok(x+1,y,mapa)){

//             cout << "HA pasado 2" << endl;
            b2=dfs(x+1,y,mapa,visit);
        }
        if (ok(x,y-1,mapa)) {
            b3=dfs(x,y-1,mapa,visit);

//             cout << "HA pasado 3" << endl;
        }

        if (ok(x,y+1,mapa)){

//             cout << "HA pasado 4" << endl;
            b4=dfs(x,y+1,mapa,visit);
        }
        return b1 or b2 or b3 or b4;
        }
        return false;

}

int main() {
    cin >> n >> m;
        VVC mapa=VVC(n,vector<char>(m));
        VVB visit=VVB(n,vector<bool>(m,false));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> mapa[i][j];
            }
        }

        int x,y; cin >> x >> y;
        if (dfs(x-1,y-1,mapa,visit)) cout << "yes" << endl;
        else cout << "no" << endl;

}
