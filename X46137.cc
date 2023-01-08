#include <iostream>
#include <vector>
using namespace std;

int n;

bool ok(int pa, int pb) {
    return abs(pa-pb)<=2;
}

void b(int k, int pa, int pb, string r) {
    if(k==n) cout << r << endl;
    else {
        int pa1=pa+1;
        if(ok(pa1,pb)) {
            r[k]='a';
            b(k+1,pa1,pb,r);
        }
        int pb1=pb+1;
        if(ok(pa,pb1)) {
            r[k]='b';
            b(k+1,pa,pb1,r);
        }
    }
}

int main() {
    cin >> n;
    string r(n,'.');
    b(0,0,0,r);
}
