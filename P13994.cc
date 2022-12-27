#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;

int ini,fi;

/*
void read_g(const VVP &G) {
  for (int i=0; i<int(G.size()); i++) {
    for (int j=0; j<int(G[i].size()); j++) {
      cout << G[i][j].second << ' ';
    }
    cout << endl;
  }
}*/

void read_v(const VI& dist) {
  for (int i=0; i<int(dist.size()); i++) {
    cout << dist[i]<< ' ';
  }
  cout << endl;
}

void read_paths(const vector<int>& p) {
    stack<int> s;
    int act = fi;
    s.push(act);
    while (p[act]!=-1) {
        s.push(p[act]);
        act = p[act];
    }
    cout << s.top(); s.pop();
    while (not s.empty()) {
        cout << ' ' << s.top();
        s.pop();
    }
    cout << endl;

}
int main() {
  int n, m;
 while( cin >> n >> m) {
  VVP G(n);
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back(P(c, y));
  }
  //read_g(G);
  cin >> ini >> fi;
  priority_queue<P> Q;
  VI dist(n, 1e9);
  Q.push(P(0, ini));
  dist[ini] = 0;
  bool found=false;
  vector<int> paths(n,-1);
    read_v(paths);
  while (not found and not Q.empty()) {
    P p = Q.top(); Q.pop();
    int d = -p.first;
    int x = p.second;
//     cout << "coste: " <<d << " vengo de: " << x << endl;
    if (d == dist[x]) {
      if (x == fi) {
//         read_paths(paths);
        found=true;
      }
      else {
          for (P arc : G[x]) {
          int d2 = d + arc.first;
          int y = arc.second;
//           cout << "hay una distancia: " << d2 << "  hasta el destino :" <<y << endl;
          if (d2 < dist[y]) {
            paths[y]=x;
            dist[y] = d2;
            Q.push(P(-d2, y));
          }
//           read_v(paths);

        }
      }
    }
  }
  if (not found)cout << "no path from "<<ini<<" to "<< fi << endl;
  }
}
