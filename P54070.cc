#include <iostream>
#include <vector>
using namespace std;

// 15 15 20 30 40 40

// ACUERDATE DEL DOUBLE, Y NO TE COMPLIQUES LA VIDA HACIENDO CASOS BASE

int dico(double x, int e, int d, const vector<double>& v) {
//     cout << e << ' ' << d << endl;

    if(e==d) return d;
    else {
        int m=(d+e)/2;
        if(v[m]<=x) {return dico(x,m+1,d,v);}
        else {return dico(x,e,m,v);}
    }
}

//OJO QUE ES V.SIZE()

int mes_a_la_dreta(double x, const vector<double>& v) {
	return dico(x,0,v.size(),v);
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
            cout << mes_a_la_dreta(x, V) << endl;
        }
    }
}
