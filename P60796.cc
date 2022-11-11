#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> coo;

int bfs ( int px, int py, vector<vector<char>>& g) {
    queue<coo> q;
    vector<vector<int>> dist (g.size(), vector<int>(g[0].size(),-1));

    q.push({px,py});
    dist[px][py]=0;

    while (q.size()>0) {
        coo punt = q.front();
        int x = punt.first;
        int y = punt.second;
        q.pop();

        if (g[x][y]=='t') return dist[x][y];
        // marcamos como punto visitado
        g[x][y] = 'X';

        if (x+1<g.size() and g[x+1][y]!='X') {
            q.push({x+1,y});
            dist[x+1][y] = dist[x][y]+1;
        }
        if (x-1>=0 and g[x-1][y]!='X') {
            q.push({x-1,y});
            dist[x-1][y]=dist[x][y]+1;
        }
        if (y+1<g[0].size() and g[x][y+1]!='X') {
            q.push({x,y+1});
            dist[x][y+1] = dist[x][y]+1;
        }
        if (y-1>=0 and g[x][y-1]!='X') {
            q.push({x,y-1});
            dist[x][y-1] = dist[x][y] +1;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> G (n, vector<char>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> G[i][j];
        }
    }

    int x,y;
    cin >> x >> y;

    int dist = bfs(x-1,y-1,G);

    if (dist == -1) cout << "no treasure can be reached" << endl;
    else cout << "minimum distance: " << dist << endl;

}
