#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P = pair<int,int>;
using VP = vector<P>;
using VI = vector<int>;
using VVI = vector<VI>;

int n,m;
int W,L;
VP po;
VVI dist;
const VP mov = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m;
}

int bfs(int xi, int yi, int xf, int yf) {
//     cout << "principio: {"<<xi<<','<<yi<<'}'<<endl;
//     cout << "final: {"<<xf<<','<<yf<<'}'<<endl;
    queue<P> q;
    q.push({xi,yi});
    dist[xi][yi]=0;
    while(not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
//         cout << '{'<<x<<','<<y<<'}'<<endl;
         q.pop();

        if(x==xf and y==yf) return dist[x][y];
        for(P p: mov) {
            int xx = x+p.first;
            int yy = y+p.second;
//             cout << '{'<<xx<<','<<y<<'}'<<endl;

            if(ok(xx,yy) and dist[xx][yy]==-1) {
                dist[xx][yy]=dist[x][y]+1;
                q.push({xx,yy});
            }
        }
    }
    return -1;
}

int main() {
    while(cin >> n >> m) {
        cin >> W>>L;
        int k; cin >> k;
        po = VP(k+1);
        po[0]={0,0};
        for(int i=1; i<=k; i++) cin >> po[i].first >> po[i].second;
        int p = 0;
        int maximum = 0;
        for(int i=1; i<=k; i++) {
            dist = VVI(n,VI(m,-1));
            int d = bfs(po[i-1].first,po[i-1].second,po[i].first,po[i].second);
            if(d==-1) i=k+1;
            else {
                p+=W;
                p-=d*L;
                if(p>maximum) maximum=p;
            }
        }
        cout << maximum << endl;
    }
}
