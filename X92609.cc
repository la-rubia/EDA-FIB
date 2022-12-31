#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
int x,n;
VI m;
VI t;

void imprimir() {
    for(int i=0; i<n; i++) {
        cout << m[i] << '-' << t[i] << ' ';
    }
    cout << endl;

}

int back(int k, int i) {
//     imprimir();
    if(k==x) return 1;
    if(i==n) return 0;

    else if(k<x){
        int r=0;
        for(int i=0; i<n; i++) {
//             t[i]=j;
            int ki = k+m[i]*j;
            r+=back(ki,i+1);
        }
        return r;
    }
    return 0;
}

int main() {
    while(cin >> x >> n) {
        m = VI(n);
//         t = VI(n,0);
        for(int i=0; i<n; i++) {
            cin >> m[i];
        }
       cout << back(0,0) << endl;
    }
}
