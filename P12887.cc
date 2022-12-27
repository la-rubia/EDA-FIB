#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VB = vector<bool>;
using T = pair<int,P>;

VB v;

int n, m;

int main() {

    while (cin >> n >> m) {

        VVP G(n);
        v= VB(n);
        for (int i=0; i<m; i++) {
            int x, y,c;
            cin >> x >> y >> c;
            G[x-1].push_back(P(c,y-1));
            G[y-1].push_back(P(c,x-1));
        }
//         cout << "He salido del bucle" << endl;

        int suma=0;
        int q=0;
        priority_queue<T,vector<T>,greater<T>> Q;
        Q.push(T(0,P(-1,0)));
        while (q<n and not Q.empty()) {
//             cout << "Entro en el bucle" << endl;
            T a = Q.top(); Q.pop();
            int c=a.first;
            int x=a.second.first;
            int y=a.second.second;
//             cout << x << ' ' << y << ' ' << c << endl;
            if (not v[y]) {
                v[y]=true;
                ++q;
                suma+=c;
                for ( P b : G[y])Q.push(T(b.first,P(y,b.second)));
            }

        }
    cout << suma << endl;
    }

}
