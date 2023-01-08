#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
VVI G;
VB d;
int n,m;

bool cicle_i(int xi,int yi) {
    queue<int> q;
    q.push(xi);
    d[xi]=true;
    while(not q.empty()) {
        int x = q.front();
        q.pop();

        if(x==yi) return true;
        else {
            for(int i=0; i<int(G[x].size()); i++) {
                int y = G[x][i];
                if(not d[y]){
                    d[y]=true;
                    q.push(y);
                }
            }
        }
    }
    return false;
}

bool cicle(int xi) {
    for(int y: G[xi]) {
        d = VB(n,false);
        if(cicle_i(y,xi)) return false;
    }
    return true;
}

int main() {
    while(cin >> n >> m) {
        G = VVI(n);
        for(int i=0; i<m; i++) {
            int u,v; cin >> u >> v;
            G[u].push_back(v);
        }
        bool b = true;
        for(int i=0; i<n and b; i++) {
            if(not cicle(i)) b=false;
        }
        if(b) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}
