
/* Es un BFS porque necesitas el camino mínimo, por lo tanto primero mirarás todos los vecinos y luego los vecinos de los vecinos, pero no harás en profundidad porque no tiene sentido ir a encontrar un tesoro a distancia 4 cuando está a distancia 1, el primero que encuentre será el más cercano*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
using VC=vector<char>;
using VVC=vector<VC>;

VVI dist;
VVC map;

int m, n;

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m and map[x][y]!='X' and dist[x][y]==-1;
}

int bfs (int xi, int yi) {
    queue<pair<int,int>> q;
    q.push({xi,yi});
    dist[xi][yi]=0;
    int max=-1;
    while (not q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if (map[x][y]=='t') if (dist[x][y]>max) max=dist[x][y];

        if (ok(x-1,y)) {
            dist[x-1][y]=dist[x][y]+1;
            q.push({x-1,y});
        }
        if (ok(x+1,y)) {
            dist[x+1][y]=dist[x][y]+1;
            q.push({x+1,y});
        }
        if (ok(x,y+1)){
            dist[x][y+1]=dist[x][y]+1;
            q.push({x,y+1});
        }
        if (ok(x,y-1)){
            dist[x][y-1]=dist[x][y]+1;
            q.push({x,y-1});
        }
    }
    return max;
}

int main() {
    cin >> n >> m;
    map=VVC(n,VC(m));
    dist=VVI(n,VI(m,-1));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    int r=bfs(x-1,y-1);
    if (r==-1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << r << endl;
}
