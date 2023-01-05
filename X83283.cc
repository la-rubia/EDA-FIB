#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
using VI = vector<int>;
using VQ=vector<priority_queue<int,VI,greater<int>>>;

VI d;
VQ G;

int maxim(const VI& d) {
    int x=0;
    int v=0;
    for(int i=1; i<n;i++){
        if(d[i]>x) {
            x=d[i];
            v=i;
        }
    }
    return v;
}

int bfs(int ini) {
    d[ini]=0;
    queue<int> q;
    q.push(ini);
    while(not q.empty()) {
        int x=q.front();
        q.pop();
        auto pq = G[x];
        while(not pq.empty()) {
            int y=pq.top(); pq.pop();
            if(d[y]==-1) {
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
    return maxim(d);
}



int main() {
  while(cin >> n >> m) {
    G = VQ(n);
    for(int i=0; i<m; i++) {
        int x,y; cin >> x >> y;
        G[x].push(y);
        G[y].push(x);
    }

    int x=0;
    d = VI(n,-1);
    x = bfs(0);

    cout << x<< endl;

}
}
