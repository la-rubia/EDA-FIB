#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
int n, t;
VVI G;
VI dist;

void escribir_grafo() {
    for(int i=0; i<int(G.size()); i++) {
        for(int j=0; j<int(G[i].size()); j++) {
            cout << G[i][j] << ' ';
        }
        cout << endl;
    }
}

void llenar_grafo(const VI& t) {
    for(int i=0; i<int(t.size()); i++) {
        for(int j=i+1; j<int(t.size()); j++) {
            G[t[i]].push_back(t[j]);
            G[t[j]].push_back(t[i]);
        }
    }
}

void assignar() {
    dist[0]=0;
    queue<int> q;
    q.push(0);
    while(not q.empty()) {
        int x=q.front(); q.pop();
        for(int i=0; i<int(G[x].size()); i++) {
            int y=G[x][i];
            if(dist[y]==-1) {
                dist[y]=dist[x]+1;
                q.push(y);
            }
        }
    }
}

void escribir() {
    for(int i=0; i<n; i++) {
        cout << i << " : ";
        if(dist[i]!=-1) cout << dist[i]<<endl;
        else cout << "no" << endl;
    }
    cout << "----------"<<endl;
}

int main() {
    while(cin >> n >> t) {
        G = VVI(n);
        dist = VI(n,-1);
        for(int i=0; i<t; i++) {
            int x; cin >> x;
            VI trabajo(x);
            for(int i=0; i<x; i++) cin >> trabajo[i];
            llenar_grafo(trabajo);
        }
//         escribir_grafo();
        assignar();
        escribir();
    }
}
