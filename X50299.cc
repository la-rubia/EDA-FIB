#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;

int n,m;
VI dist;
VVP g;

int main() {
    while(cin >> n >> m) {
        g = VVP(n);
        for(int i=0; i<m; i++) {
            int x, y, l;
            cin >> x >> y >> l;
            g[x].push_back({l,y});
        }
        dist = VI(n,1e9);
        dist[0]=-1;
        priority_queue<P,VP, greater<P>> pq;
        pq.push({-1,0});
        while(not pq.empty()) {
            P p = pq.top();
            int l = p.first;
            int x = p.second;
            pq.pop();
//             cout << "estamos en la pareja: "<<l << ' ' << x << endl;
            if(l==dist[x]) {
                for(int i=0; i<int(g[x].size()); i++) {
//                     cout << "podemos acceder a la y: "<< g[x][i].second << " y la arista que los une es: " << g[x][i].first << endl;
                    int y = g[x][i].second;
                    int l2 = max(l,g[x][i].first);
                    if(l2<dist[y]) {
//                         cout << "hemos entrado!!" << endl;
                        dist[y]=l2;
                        pq.push({dist[y],y});
                    }
                }
            }
        }
        cout << dist[1] << endl;
    }
}
