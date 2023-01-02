#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VB = vector<bool>;

int n;
VC c,v;
VB cv,vv;

void back(int k, string s) {
//     cout << k << ' ' << s << endl;
    if(k==2*n) cout << s << endl;
    for(int i=0; i<n; i++) {
        if(k%2==0) {
            // hay que poner consonantes
            if(not cv[i]) {
                cv[i]=true;
                s[k]=c[i];
                back(k+1,s);
                cv[i]=false;
            }
        }
        else {
            if(not vv[i]) {
                vv[i]=true;
                s[k]=v[i];
                back(k+1,s);
                vv[i]=false;
            }
        }
    }
}

int main() {
    cin >> n;
    c = VC(n); cv = VB(n,false);
    for(int i=0; i<n; i++) cin >> c[i];
    v = VC(n); vv = VB(n,false);
    for(int i=0; i<n; i++) cin >> v[i];
    string s(2*n,'.');
    back(0,s);
}
