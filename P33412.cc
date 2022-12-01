#include <iostream>
#include <vector>
using namespace std;


bool dico(double x, const vector<double>& v, int e, int d) {
    if (e>d) return false;
    int m=(e+d)/2;
    double y=v[m];
    if (m-1>=0 and v[m-1]>v[m]) y=v[m-1];
    if (m+1<v.size() and v[m+1]<v[m]) y=v[m+1];
    if (y>x) return dico(x,v,e,m-1);
    else if (y<x) return dico(x,v,m+1,d);
    else return true;
}


bool resistant_search(double x, const vector<double>& v) {
    return dico(x,v,0,v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        double x;
        while (cin >> x) cout << resistant_search(x, V) << endl;
        }
    }
