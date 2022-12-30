#include <iostream>
#include <vector>
using namespace std;

using VC=vector<char>;
using VVC = vector<VC>;
using P = pair<int,int>;
using VP = vector<P>;

VVC T;
int n,m;

const VP mov = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};


bool ok(int x, int y) {
//      cout << '{'<<x<<','<<y <<"} ok" << endl;
    return x>=0 and y>=0 and x<n and y<m and T[x][y]!='X';
}

bool segura(int x, int y) {
//      cout << '{'<<x<<','<<y <<"} segura" << endl;
    if(T[x][y]=='F') return false;
    for(P p:mov) {
        int xx = x+p.first;
        int yy = y+p.second;
        if(T[xx][yy]=='F') return false;
    }
    return true;
}

bool dfs(int x, int y) {
 /*   for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << T[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << x << ' ' << y << endl;*/
    if(T[x][y]=='B') return true;
    else if(segura(x,y)) {
        T[x][y]='X';
        bool b1=false,b2=false,b3=false,b4=false;
        if(ok(x+1,y) and segura(x+1,y)) b1=dfs(x+1,y);
        if(ok(x-1,y) and segura(x-1,y)) b2=dfs(x-1,y);
        if(ok(x,y+1) and segura(x,y+1)) b3=dfs(x,y+1);
        if(ok(x,y-1) and segura(x,y-1)) b4=dfs(x,y-1);
        return b1 or b2 or b3 or b4;
    }
    return false;
}


int main() {
    while(cin >> n >> m) {
        T = VVC(n,VC(m));
        int xi=0,yi=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> T[i][j];
                if(T[i][j]=='P') {
                    xi=i;
                    yi=j;
                }
            }
        }
        if(dfs(xi,yi)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
