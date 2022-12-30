#include <iostream>
#include <vector>
using namespace std;

using VC=vector<char>;
using VVC=vector<VC>;
using P = pair<int,int>;
using VP = vector<P>;
using VB = vector<bool>;
using VVB = vector<VB>;

int n,m;
VVC T;
int suma;
VVB v;

const VP mov_B = {{1,1},{1,-1},{-1,1},{-1,-1}};
const VP mov_K = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};

bool ok(int x, int y) {
    return x>=0 and y>=0 and x<n and y<m and not v[x][y];
}

void dfs(int x, int y, char c) {
//     cout << x << ' ' << y << endl;
    if (ok(x,y) and T[x][y]>='0' and T[x][y]<='9') {
        suma+=T[x][y]-'0';
        T[x][y]='.';
    }

    if (not v[x][y]) {
        v[x][y]=true;
        if(c=='B') {
            for(P p:mov_B) {
                if(ok(x+p.first,y+p.second) and T[x+p.first][y+p.second]!='T') dfs(x+p.first,y+p.second,'B');
            }
        }
        if(c=='K') {
            for(P p:mov_K) {
                if(ok(x+p.first,y+p.second) and T[x+p.first][y+p.second]!='T') dfs(x+p.first,y+p.second,'K');
            }
        }
    }
}


int main() {
    while(cin >> n >> m) {
        T = VVC(n,VC(m));
        VP B;
        VP K;
        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> T[i][j];
                if(T[i][j]=='B')B.push_back({i,j});
                if(T[i][j]=='K')K.push_back({i,j});
            }
        }

        /*cout << "los B: {";
        for(P x: B) cout << x.first<<','<<x.second<<"},";
        cout << '}'<<endl;
        cout << "los K: {";
        for(P x: K) cout << x.first<<','<<x.second<<"},";
        cout << '}'<<endl;*/
        suma=0;
        v = VVB(n,VB(m,false));
        for(P x: B) {
            dfs(x.first,x.second,'B');
        }
        v = VVB(n,VB(m,false));
        for(P x: K) {
            dfs(x.first,x.second,'K');
        }
        cout << suma << endl;
    }
}
