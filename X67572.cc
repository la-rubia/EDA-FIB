#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VS = vector<string>;
using VB = vector<bool>;
VS s;
VB v;
int n;

bool ok(string r, string s) {
    int n = r.size();
    return r[n-1]!=s[0];
}

void b(int k, VS r) {
    if(k==n) {
        for(string se: r) cout << se;
        cout << endl;
    }
    else {
        for(int i=0; i<n; i++) {
            if(not v[i]) {
                if(k==0 or ok(r[k-1],s[i])) {
                    v[i]=true;
                    r[k]=s[i];
                    b(k+1,r);
                    v[i]=false;
                }
            }
        }
    }
}


int main() {
    cin >> n;
    v = VB(n,false);
    s = VS(n);
    for(string& se: s) cin >> se;
    VS r(n);
    b(0,r);
}
