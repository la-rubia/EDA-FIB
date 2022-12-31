#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int,int>;

int n,m;
VVC T;
VVI d;
int smax=1e9;
int ffmax=1e9;

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m and T[x][y]!='X';
}

int bfs(int xi, int yi) {
    queue<P> q;
    q.push({xi,yi});
    d[xi][yi]=0;
    while(not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(T[x][y]=='t') {
            smax=ffmax;
            ffmax=d[x][y];
        }
        T[x][y]='X';
            if(ok(x+1,y) and d[x+1][y]==1e9) {
                d[x+1][y]=d[x][y]+1;
                q.push({x+1,y});
            }
            if(ok(x-1,y) and d[x-1][y]==1e9) {
                d[x-1][y]=d[x][y]+1;
                q.push({x-1,y});
            }
            if(ok(x,y+1) and d[x][y+1]==1e9) {
                d[x][y+1]=d[x][y]+1;
                q.push({x,y+1});
            }
            if(ok(x,y-1) and d[x][y-1]==1e9) {
                d[x][y-1]=d[x][y]+1;
                q.push({x,y-1});

        }
    }
    return smax;
}

int main() {
    cin >> n >> m;
    T = VVC(n,VC(m));
    d = VVI(n,VI(m,1e9));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> T[i][j];
        }
    }
    int xi, yi; cin >> xi >> yi;
    int r = bfs(xi-1,yi-1);
    if(r==1e9) cout << "we cannot reach two or more treasures" << endl;
    else cout << "second maximum distance: " << r << endl;
}
