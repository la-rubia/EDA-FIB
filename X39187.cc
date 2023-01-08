#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n,c;

void b(int k, int m, int a, string r) {
    if(k==n)cout << r << endl;
    else {
        if(m-1>=0) {
            r[k]='b';
            b(k+1,m-1,a+1,r);
        }
        if(a-1>=0) {
            r[k]='s';
            b(k+1,m+1,a-1,r);
        }
    }
}

int main() {
    cin >> n >> c;
    string r(n,'.');
    b(0,c,0,r);
}
