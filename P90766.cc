#include <iostream>
#include <vector>
using namespace std;

int n,m;
using VC=vector<char>;
using VVC=vector<VC>;
using VB=vector<bool>;
using VVB=vector<VB>;

VVC mapa;
VVB visit;

bool ok(int x, int y) {
    return x>=0 and x<n and y>=0 and y<m and mapa[x][y]!='X';
}

int dfs(int x, int y) {
    if (visit[x][y]) return 0;

    visit[x][y]=true;
    int c=0,c1=0,c2=0,c3=0,c4=0;

    if (mapa[x][y]=='t') c++;
    if (ok(x-1,y))c1=dfs(x-1,y);
    if (ok(x+1,y))c2=dfs(x+1,y);
    if (ok(x,y-1))c3=dfs(x,y-1);
    if (ok(x,y+1))c4=dfs(x,y+1);

    c+=c1+c2+c3+c4;
    return c;
}

int main() {
    cin >> n >> m;
        mapa=VVC(n,vector<char>(m));
        visit=VVB(n,vector<bool>(m,false));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> mapa[i][j];
            }
        }

        int x,y; cin >> x >> y;
        cout << dfs(x-1,y-1)<< endl;
}
