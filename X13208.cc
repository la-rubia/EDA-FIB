#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
using P = pair<int,int>;
using VP = vector<P>;
using T = pair<int,P>;
using VT = vector<T>;
int n;
VVI G;
int minim;
VVI d;

const VP mov = {{1,0},{-1,0},{0,1},{0,-1}};

bool ok(int x, int y) {
//     cout << "pruebo: " << x << ' ' << y << endl;
    return x>=0 and y>=0 and x<n and y<n;
}

int main() {
    while(cin >> n) {
        G = VVI(n,VI(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> G[i][j];
            }
        }
        minim=1e9;

        // bfs
        d = VVI(n,VI(n,1e9));
        int ini=n/2;
        d[ini][ini]=G[ini][ini];
        priority_queue<T,VT,greater<T>> pq;
        pq.push({G[ini][ini],{ini,ini}});
        while(not pq.empty()) {
            T t=pq.top(); pq.pop();
            int c=t.first;
            int x = t.second.first;
            int y = t.second.second;
//             cout << x << ' ' << y << ' ' << c << endl;
            if(c==d[x][y]) {
                if(x==0 or y==0 or x==n-1 or y==n-1) {
                    minim=min(c,minim);
                }
                for(P p: mov) {
                    int xx=x+p.first;
                    int yy=y+p.second;
                    if(ok(xx,yy)) {
                        int d2 = c+G[xx][yy];

                        if(d[xx][yy]>d2) {
                            d[xx][yy]=d2;
                            pq.push({d2,{xx,yy}});
                        }
                    }
                }
            }
        }
        cout << minim << endl;
    }
}
