#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P =pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;

VVP G;
VI w;
VI cost;

int n,m;

int main() {
    int n,m;
    while(cin >> n >> m) {
        G = VVP(n);
        w = VI(n);

        for(int i=0; i<n; i++) cin >> w[i];
        for(int i=0; i<m; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            G[x].push_back({y,d});
            G[y].push_back({x,d});
        }

        int ini,fi;
        while(cin >> ini >> fi) {
            cost = VI(n,1e9);
            priority_queue<P,VP,greater<P>> Q;
            Q.push({0,ini});
            cost[ini]=0;
            bool found=false;
            while(not found and not Q.empty()) {
//                 for(int x: cost) cout << x << ' ';
//                 cout << endl;
                P p = Q.top(); Q.pop();
                int c = p.first;
                int x = p.second;
                if(c==cost[x]) {
                    if(x==fi) {
                        cout << "c("<<ini<<','<<fi<<") = "<<cost[fi] << endl;
                        found=true;
                    }
                    else {
                        for(P arc: G[x]) {
                            int c2 = cost[x]+ arc.second;
                            int y = arc.first;
                            if(y!=fi) c2 = c2+ w[y];
                            if(c2<cost[y]) {
                                cost[y]=c2;
                                Q.push({c2,y});
                            }
                        }
                    }
                }
            }
            if(not found) cout << "c("<<ini<<','<<fi<<") = +oo"<<endl;
        }
    }
}
