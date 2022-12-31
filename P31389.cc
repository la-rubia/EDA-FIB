#include <iostream>
#include <vector>
using namespace std;

using VB=vector<bool>;
using VI = vector<int>;
VI h; // en que fila está de la columna
VB v; // ya hay alguna torre en la fila?
int n,m;

void write() {
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(h[i]==j)cout << 'R';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}


void back(int x, int k) {
    if(k==n) write();
    else {
        for(int i=0; i<m; i++) {
            if(not v[i]) {
                h[k]=i;
                v[i]=true;
                back(x,k+1);
                v[i]=false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    v = VB(m);
    h = VI(n);
    back(0,0);
}
