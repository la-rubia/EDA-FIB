#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
VB v;
int n;

void write(const VI& r) {
    cout << '(';
    bool primer=true;
    for(int x: r) {
        if(primer) {
            cout << x;
            primer=false;
        }
        else {
            cout << ',' << x;
        }
    }
    cout << ')' << endl;
}

bool pont(int a, int b, int c) {
    return a+c>2*b;
}


void b(int k, VI r) {
    if(k==n) write(r);
    else {
        for(int i=0; i<n; i++) {
            if(not v[i]) {
                if(k==0 or k==1 or not pont(r[k-2],r[k-1],i+1)) {
                    v[i]=true;
                    r[k]=i+1;
                    b(k+1,r);
                    v[i]=false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    VI r(n);
    v = VB(n,false);
    b(0,r);
}
