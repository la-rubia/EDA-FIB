#include <iostream>
#include <vector>
using namespace std;

using VB = vector<bool>;

VB v;
int n;


void escribir(const vector<char>& r) {
    for(char c: r) cout << c;
    cout << endl;
}

void back(int k, vector<char> r) {
    if(k==n) {
        escribir(r);
    }
    else {
        for(int i=0; i<n; i++) {
            if(not v[i]){
                v[i]=true;
                int c='a'+i;
                r[k]=c;
                if(k==0) back(k+1,r);
                else {
                    if((r[k]-r[k-1])!=1) back(k+1,r);
                }
                v[i]=false;
            }
        }
    }
}

int main() {
    cin >> n;
    v = VB(n,false);
    vector<char>r(n);
    back(0,r);
}
