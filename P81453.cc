#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

const int INF = 1e9;
VVI T;
VI dist;
VVI rec;
int n,m;

void imprimir(vector<int> q) {
    bool primer=true;
    for(int x: q) {
        if(primer) {
            cout << x;
            primer=false;
        }
        else cout << ' '<<x;
    }
}

void bfs(int xi) {
    queue<int> q;
    q.push(xi);
    dist[xi]=0;
    while(not q.empty()) {
        int x = q.front(); q.pop();
        if(x==n-1) return;
        else {
            for(int i=0; i<int(T[x].size()); i++) {
                int y = T[x][i];
                if(dist[y]==1e9) {
                    dist[y]=dist[x]+1;
                    q.push(y);
                    rec[y]=rec[x];
                    rec[y].push_back(x);
                }
            }
        }
    }
}

int main() {
    while(cin>> n >> m) {
        T= VVI(n);
        dist = VI(n,INF);
        rec = VVI(n);
        for(int i=0; i<m; i++) {
            int x, y; cin >> x >> y;
            T[x].push_back(y);
        }

        for(int i=0; i<n; i++) {
            sort(T[i].begin(), T[i].end());
        }

        /*for(int i=0; i<n; i++) {
            for(int j=0; j<int(T[i].size()); j++) {
                cout << T[i][j] << ' ';
            }
            cout << endl;
        }*/


        bfs(0);
        imprimir(rec[n-1]);
        cout <<' '<< n-1<<endl;
    }
}
