#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;

using VB = vector<bool>;
using VVB = vector<VB>;

VVC T;
int n,r;

const int DI[8] = {-1,-1,-1,1,1,1,0,0};
const int DJ[8] = {0,1,-1,0,1,-1,1,-1};

bool ok(int i,int j) {
//     cout << "comprobar: "<<i <<' '<<j<<endl;
    return i>=0 and j>=0 and i<n and j<n;

}

bool safe(int i, int j) {
    if (T[i][j]=='K') return false;
    for (int k=0; k<8; k++) {
        int ii = i+DI[k];
        int jj = j+DJ[k];
        if (ok(ii,jj) and T[ii][jj]=='K') return false;
    }
    return true;
}

void write() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << T[i][j];
        }
        cout << endl;
    }
    cout << "----------" <<endl;
}

void back(int x, int y, int k) {
//     cout << x << ' ' << y << ' ' << k <<endl;
    if (k==r) {
        write();
    }
    else {
        bool first=true;
       for(int i=x; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (first) {
                first=false;
                j=y;
            }
            if (safe(i,j)) {
                T[i][j] = 'K';
                back(i,j,k+1);
                T[i][j]='.';
            }
            }
        }
    }
}

int main() {
    cin >> n >> r;
    T = VVC(n,VC(n,'.'));
    back(0,0,0);
}
