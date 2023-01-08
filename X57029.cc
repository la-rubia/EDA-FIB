#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
const VC pas = {'d','h','u'};
int n;

int convert(char c) {
    if(c=='u') return 1;
    if(c=='d') return -1;
    return 0;
}

void b(int k, VC r,int h) {
    if(k==n){
        for(char c:r) cout << c;
        cout << endl;
    }
    else {
        for(int i=0; i<3; i++) {
            int a = h+convert(pas[i]);
            if(a>=0) {
                r[k]=pas[i];
                b(k+1,r,a);
            }
        }
    }
}

int main() {
    cin >> n;
    VC r(n,'.');
    b(0,r,0);
}
