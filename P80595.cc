#include <iostream>
#include <vector>
using namespace std;


int merge(vector<int>& v, int e, int m, int d) {
    vector<int> b(d-e+1);
    int res=0;
    int i=e;
    int j=m+1;
    int k=0;
    while (i<=m and j<=d)
        if (v[i]<=v[j]) b[k++]=v[i++];
        else {
            res+=m-i+1;
            b[k++]=v[j++];
        }
    while (i<=m) b[k++]=v[i++];
    while (j<=d) b[k++]=v[j++];
    for (int z=0; z<=d-e; ++z) v[e+z]=b[z];
    return res;
}

int mergesort(vector<int>& v, int e, int d) {
    if (e>=d) return 0;
    int m=(e+d)/2;
    int p1=mergesort(v,e,m);
    int p2=mergesort(v,m+1,d);
    int p3=merge(v,e,m,d);
    return p1+p2+p3;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        int r=mergesort(v,0,n-1);
        cout << r << endl;

    }
}
