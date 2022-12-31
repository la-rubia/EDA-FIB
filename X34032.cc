#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VC = vector<char>;
using VVC  = vector<VC>;
using P = pair<int,int>;
using VP = vector<P>;
using VI = vector<int>;
using VVI = vector<VI>;

int n,m;
VVC T;
VVI dist;
int dp;
const VP mov = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};


bool ok(int x, int y) {
//     cout << "comprobando: {" << x << ',' << y <<'}'<< endl;
    return x>=0 and y>=0 and x<n and y<m and T[x][y]!='X';
}

int bfs(int xi, int yi) {
    queue<P> q;
    q.push({xi,yi});
    dist[xi][yi]=0;
    while(not q.empty()) {
        int x=q.front().first;
        int y = q.front().second;
//         cout << x << ' ' << y << endl;
        q.pop();
        if(T[x][y]=='p') return dist[x][y];
        else{
            for(P p: mov) {
                int xx = x+p.first;
                int yy = y+p.second;
                if(ok(xx,yy) and dist[xx][yy]==1e9) {
                    dist[xx][yy]=dist[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
    }
    return 1e9;
}

int main() {
    while(cin >> n >> m) {
        T = VVC(n,VC(m));
        dist = VVI(n,VI(m,1e9));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> T[i][j];
            }
        }
        int xi, yi; cin >> xi>> yi;
        int dp=bfs(xi-1,yi-1);
        if(dp==1e9) cout << "no"<<endl;
        else cout << dp << endl;
    }
}
