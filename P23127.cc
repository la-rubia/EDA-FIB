#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;

using P = pair<int,int>;
using M = map<string,int>;
using MP = map<string,P>;
using VI = vector<int>;
using VVI = vector<VI>;

string find(const M& m, int x) {
    for(auto p: m) {
        if(p.second==x) return p.first;
    }
    return "no encontrado";
}

P contar(const VVI& v, int x) {
    P p={0,0};
    for(int i=0; i<n; i++) {
        int l=v[i][x];
        if(l==1) p.first++;
        if(l==0) p.second++;
    }
    return p;
}

int main() {
    while(cin >> n) {
        MP prop;
        M per;
        VVI v(n,VI(n,-1));
        // llegir dades
        for(int i=0; i<n; i++) {
            string n; string p;
            cin >> n >> p;
            prop[p]={i,0};
            per[n]=i;
        }
        int m;
        cin >> m;
        for(int i=0; i<m; i++) {
            string name, r, p;
            cin >> name >> r >> p;
            int x = per[name];
            int y = prop[p].first;
            if(v[x][y]==-1) {
                if(r=="SI") {
                    v[x][y]=1;
                    prop[p].second+=1;
                }
                else {
                    v[x][y]=0;
                    prop[p].second-=1;
                }
            }
            else {
                if(r=="SI" and v[x][y]==0) {
                    v[x][y]=1;
                    prop[p].second=prop[p].second+2;
                }
                else if(r=="NO" and v[x][y]==1){
                    v[x][y]=0;
                    prop[p].second=prop[p].second-2;
                }
            }
            /*for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    cout << v[i][j] <<' ';
                }
                cout << endl;
            }
            cout << endl;
            cout << prop[p].second;*/
        }

        for(auto it=prop.begin(); it!=prop.end(); it++) {
            if(((it->second).second)>0) {
                cout << it->first << ", de ";
                int x = ((it->second).first);
                string y = find(per,x);
                cout << y << ", que ha guanyat ";
                P p = contar(v,x);
                cout << p.first<<'-'<<p.second << endl;
            }
        }
        cout << "----------" << endl;
    }
}

