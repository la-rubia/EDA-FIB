#include <iostream>
#include <vector>
using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
using VBB=vector<pair<bool,bool>>;
int n,m;

VVI g;
VBB v;

void read_vector(const VBB& v) {
    for (int i=0; i<n; i++) {
         cout <<'{' <<v[i].first <<','<<v[i].second<<"} ";
        }
        cout << endl;
}

bool subsearch(int i, int ia) {
//     read_vector(v);
    if (v[i].first) {
        if (v[i].second==v[ia].second and i!=ia) {
//             cout << "primero: ";
            return false;
        }
    }

    else {
    v[i].first=true;
    v[i].second=!v[ia].second;
    for (int j=0; j<g[i].size(); j++) {
        if (g[i][j]!=i) {
            bool b=subsearch(g[i][j],i);
            if (not b) {
//                 cout << "segundo: ";
                return false;
            }
        }
    }}
    return true;
}

bool pintar() {
    for (int i=0; i<n; i++) {
        bool b=subsearch(i,i);
        if (not b) return false;

    }
    return true;
}

int main() {
    while(cin >> n >> m) {
    g=VVI(n);
    v=VBB(n,{false,false});
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (pintar()) cout << "yes" << endl;
    else cout << "no" << endl;
}}
