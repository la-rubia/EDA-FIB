#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VB = vector<bool>;
VVP G;
VB v;
int n,m;

void read(priority_queue<P,vector<P>,greater<P>> pq) {
    auto q=pq;
    while(not q.empty()) {
        cout <<'{'<< q.top().first <<','<< q.top().second << "} ";
        q.pop();
    }
    cout << endl;
}


int main() {
    while(cin >> n >> m) {
        G = VVP(n);
        int t = 0;
        for(int i=0; i<m; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            G[x].push_back({c,y});
            G[y].push_back({c,x});
            t+=c;
        }
        v = VB(n,false);
        v[0]=true;
        priority_queue<P,vector<P>,greater<P>> pq;
        for(P p: G[0]) pq.push(p);
        int q = 1;
        int sum = 0;
        while(q<n and not pq.empty()) {
//             read(pq);
            int c = pq.top().first;
            int x = pq.top().second;
            pq.pop();
            if(not v[x]) {
                v[x]=true;
                sum+=c;
                ++q;
                for(P p: G[x]) pq.push(p);
            }
        }
        cout << t-sum << endl;
    }
}
