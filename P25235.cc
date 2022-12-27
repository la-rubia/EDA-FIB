#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;


void read_g(const VVP &G) {
  for (int i=0; i<int(G.size()); i++) {
    for (int j=0; j<int(G[i].size()); j++) {
      cout << G[i][j].second << ' ';
    }
    cout << endl;
  }
}

void read_v(const VI& dist) {
  for (int i=0; i<int(dist.size()); i++) {
    cout << dist[i]<< ' ';
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
  int ini, fi;
  cin >> ini >> fi;
  priority_queue<P> Q;
  VI dist(n, 1e9);
  VI steps(n,1e9);
  Q.push(P(0, ini));
  dist[ini] = 0;
  steps[ini]=0;
  bool found=false;
//   read_v(steps);
  while (not found and not Q.empty()) {
    P p = Q.top(); Q.pop();
    int d = -p.first;
    int x = p.second;
//     cout << "coste: " <<d << " vengo de: " << x << endl;
    if (d == dist[x]) {
      if (x == fi) {
        cout << "cost "<< d <<", "<< steps[fi] << " step(s)"<< endl;
        found=true;
      }
      else {
          for (P arc : G[x]) {
          int d2 = d + arc.first;
          int y = arc.second;
          int p2 = steps[x]+1;
//           cout << "hay una distancia: " << d2 << "  hasta el destino :" <<y << endl;
          if (d2 < dist[y] or (d2 == dist[y] and p2<steps[y])) {
            dist[y] = d2;
            steps[y]=p2;
            Q.push(P(-d2, y));
          }
//            read_v(steps);
        }
      }
    }
  }
  if (not found)cout << "no path from "<<ini<<" to "<< fi << endl;
  }
}

