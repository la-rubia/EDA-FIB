#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

VB v;
VI s;
int m,n; // m longitud, n número de salts

void back(int l, int k) {
//     cout << l << ' ' << k << endl;
    if(k==n) cout << l<< endl;
    else {
//         cout << "entro en 2" << endl;
        if(not v[k]) {
//             cout << "he entrado en el if" << endl;
            v[k]=true;
            int x = s[k];
            if(abs(l+x)<=m/2) back(l+x,k+1);
            v[k]=false;
            int y = s[k];
            if(abs(l-y)<=m/2) back(l-y,k+1);
        }
    }
}

int main() {
    cin >> m >> n;
    v = VB(n,false);
    s = VI(n);
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }

    back(0,0);
}
