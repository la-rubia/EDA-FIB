#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

using VS = vector<string>;
using VVS = vector<VS>;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VP = vector<P>;

const VP mov = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,p;
VVS t;
VS r;
VVI d;
int xi,yi;

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m and t[x][y]!="*";
}

int bfs(string p) {
//     cout << "entramos en bfs" << endl;

    queue<P> q;
    q.push({xi,yi}); d[xi][yi]=0;

    while(not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
//         cout << '{'<<x<<','<<y<<'}'<<endl;

        if(t[x][y]==p) {
            xi=x;
            yi=y;
            return d[x][y]+1;
        }
        else {
            for(int i=0; i<4; i++) {
                int xx=x+mov[i].first;
                int yy=y+mov[i].second;
//                 cout << '{'<<xx<<','<<yy<<'}'<<endl;
                if(ok(xx,yy) and d[xx][yy]==-1) {
                    d[xx][yy]=d[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
    }
    xi=-1;
    yi=-1;
    return -1;
}


int main() {
    while(cin >> n >> m) {
        t = VVS(n,VS(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> t[i][j];
            }
        }
        cin >> p;
        r = VS(p);
        for(int i=0; i<p; i++) cin >> r[i];
        int c=0;
        bool tot_be=true;
        xi=0;
        yi=0;
        for(int i=0; i<p; i++) {
            d = VVI(n,VI(m,-1));
            int result = bfs(r[i]);
            if(result==-1) {
                tot_be=false;
                break;
            }
            c+=result;
        }
        if(tot_be)cout << c << endl;
        else cout << "impossible" << endl;
    }
}
