#include <iostream>
#include <vector>
using namespace std;


int fixed_point(const vector<int>&S, int a, int e, int d) {
    if (e>d) return -1;
    int m=(e+d)/2;
    if (m+1==S[m]+a and (m==0 or m>S[m-1]+a)) return m+1;
    else if (m+1>S[m]+a) return fixed_point(S,a,m+1,d);
    else return fixed_point(S,a,e,m-1);
}

int main() {
    int n;
    int c=1;
    while (cin >> n) {
        cout << "Sequence #" << c << endl;
        vector<int> S(n);
        for (int i=0; i<n ; i++) cin >> S[i];
        int t; cin >> t;
        while (t--) {
            int a; cin >> a;
            int r=fixed_point(S,a,0,S.size()-1);
            if (r==-1) cout << "no fixed point for " << a << endl;
            else cout << "fixed point for " << a << ": " << r << endl;
        }
        cout << endl;
        c++;
    }
}
