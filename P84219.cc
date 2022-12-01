#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
    if (left>right)return -1;
    int m=(left+right)/2;
    if (x<v[m]) return position(x,v,left,m-1);
    if (x>v[m]) return position(x,v,m+1,right);
    else if (x==v[m]) {
        if (m>0 and x==v[m-1]) return position(x,v,left,m-1);
        else return m;
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return position(x,v,0,v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
