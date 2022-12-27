#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;

VVC T;
VVB v;
int n,m;
int xi,yi,xf,yf;

bool ok(int i,int j) {
    return i>=0 and j>=0 and i<n and j<m;
}

void back(int x, int y, string s) {
//     cout << x << ' ' << y << endl;
    s+=T[x][y];
    v[x][y]=true;
    if (x==xf and y==yf) {
        cout << s << endl;
        return;
    }

    if(ok(x+1,y) and not v[x+1][y]){
        v[x+1][y]=true;
        back(x+1,y,s);
        //
        v[x+1][y]=false;
    }
    if(ok(x-1,y) and not v[x-1][y]){
        v[x-1][y]=true;
        back(x-1,y,s);
        v[x-1][y]=false;
    }
    if(ok(x,y+1) and not v[x][y+1]){
        v[x][y+1]=true;
        back(x,y+1,s);
        v[x][y+1]=false;
    }
    if(ok(x,y-1) and not v[x][y-1]){
//         cout << "he entrado" << endl;
        v[x][y-1]=true;
        back(x,y-1,s);
        v[x][y-1]=false;
    }

}

int main() {
    cin >> n >> m;
    T = VVC(n,VC(m));
    v = VVB(n,VB(m,false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> T[i][j];
        }
    }

    cin >> xi >> yi;
    cin >> xf >> yf;
    string s = "";
    back(xi,yi,s);
}
