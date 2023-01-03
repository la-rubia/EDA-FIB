#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

int n,d;
VB v;

void write(const VI& r) {
    bool primer=true;
    cout <<'(';
    for(int x: r) {
        if(primer) {
            cout << x+1;
            primer=false;
        }
        else {
            cout << ',' << x+1;
        }
    }
    cout << ')'<<endl;
}

void b(int k, VI r) {
    if(k==n) write(r);
    else {
        for(int i=0; i<n; i++) {
            if(not v[i]) {
                v[i]=true;
                if(k==0 or abs(r[k-1]-i)<=d) {
                    r[k]=i;
                    b(k+1,r);
                }
                v[i]=false;
            }
        }
    }
}

int main() {
    cin >> n >> d;
    v = VB(n,false);
    VI r(n);
    b(0,r);
}
