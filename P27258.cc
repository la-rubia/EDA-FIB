#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
int n,m;
VVC T;
int xi,yi;
const vector<pair<int,int>> mov = {{0,1},{0,-1},{1,0},{-1,0}};

bool ok(int x, int y) {
//     cout << "casco"<<endl;
    return x>=0 and y>=0 and x<n and y<m and T[x][y]!='X';
}

bool segura(int x, int y) {
//     cout << "casco2"<<endl;
    if(T[x][y]=='M') return false;
    if(ok(x+1,y) and T[x+1][y]=='M') return false;
    if(ok(x-1,y) and T[x-1][y]=='M') return false;
    if(ok(x,y+1) and T[x][y+1]=='M') return false;
    if(ok(x,y-1) and T[x][y-1]=='M') return false;
    return true;
}

bool dfs(int x, int y) {
//     cout << x << ' ' << y << endl;
    if(T[x][y]=='F') {
        return true;
    }
    else {
        if(T[x][y]!='M')T[x][y]='X';
        for(pair<int,int> p: mov) {
            int xx = x+p.first;
            int yy = y+p.second;
            if(ok(xx,yy) and segura(xx,yy)) {
                bool r = dfs(xx,yy);
                if(r) return true;
            }
        }
        return false;
    }
}

int main() {
    while(cin >> n >> m) {
        T = VVC(n,VC(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> T[i][j];
                if(T[i][j]=='I') {
                    xi=i; yi=j;
                }
            }
        }
        if(dfs(xi,yi)) cout << "SI"<<endl;
        else cout << "NO"<<endl;
    }
}
