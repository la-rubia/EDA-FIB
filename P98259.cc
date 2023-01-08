#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;

int n,m;
VVC T;
VVP d;
const VP mov = {{0,1},{0,-1},{1,0},{-1,0}};
int xf,yf;

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m and T[x][y]!='#';
}

P bfs(int xi, int yi) {
    d[xi][yi]={0,0};
    queue<P> q;
    q.push({xi,yi});
    while(not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
            if(T[x][y]=='P') d[x][y].second++;
            for(int i=0; i<4; i++) {
                int xx = x+mov[i].first;
                int yy = y+mov[i].second;

                if(ok(xx,yy) and d[xx][yy].first==-1) {
                    d[xx][yy].first=d[x][y].first+1;
                    d[xx][yy].second=d[x][y].second;
                    q.push({xx,yy});
                }
                else if(ok(xx,yy) and d[xx][yy].first==d[x][y].first+1) {
                    d[xx][yy].second=max(d[xx][yy].second,d[x][y].second);
                }
            }
        }
    return d[xf][yf];
}

int main() {
    while(cin >> n >> m) {
        T = VVC(n,VC(m));
        xf=-1;
        yf=-1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> T[i][j];
                if(T[i][j]=='T') {
                    xf=i;
                    yf=j;
                }
            }
        }
        if(xf==-1) cout << "El telecos ha fugit." << endl;
        else {
            d = VVP(n,VP(m,{-1,0}));
            P p = bfs(0,0);
            if(p.first==-1) cout << "El telecos esta amagat."<<endl;
            else cout << p.first << ' ' << p.second << endl;
        }
    }
}
