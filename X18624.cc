#include <iostream>
#include <vector>
#include <set>
using namespace std;

using VC = vector<char>;
int n,m;
VC l;

bool vocal(char c) {
    return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
}

void b(int k, string r, set<string>& s) {
    if(k==n) s.insert(r);
    else {
        for(int i=0; i<m; i++) {
            if(k==0) {
                r[k]=l[i];
                b(k+1,r,s);
            }
            else if(vocal(r[k-1])) {
                if(not vocal(l[i])) {
                    r[k]=l[i];
                    b(k+1,r,s);
                }
            }
            else if(not vocal(r[k-1])) {
                r[k]=l[i];
                b(k+1,r,s);
            }
        }
    }
}

void write_s(const set<string>& s) {
    for(string x: s) cout << x << endl;
}

int main() {
    while(cin >> n >> m) {
        l = VC(m);
        for(char& c: l) cin >> c;
        string r(n,'.');
        set<string> s;
        b(0,r,s);
        write_s(s);
        cout << "----------"<<endl;
    }
}
