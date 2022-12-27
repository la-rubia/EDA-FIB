#include <iostream>
#include <vector>
using namespace std;

int n;

void write(vector<int>& v, int k) {
    if (k==n) {
        bool primer=true;
        for (int i=0; i<n; i++) {
            if (primer) {
                primer=false;
                cout <<v[i];
            }
            else cout << ' '<< v[i];
        }
        cout << endl;
    }
    else {
        v[k]=0; write(v,k+1);
        v[k]=1; write(v,k+1);
    }
}

int main() {
    cin >> n;
    vector<int>v (n);
    write(v,0);
}
