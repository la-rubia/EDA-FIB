#include <iostream>
#include <vector>
using namespace std;

// Pre: k indica el índice del vector, c indica el número de 1 que hay en el vector

void hacer(vector<int> &v, int n, int o, int k, int c) {
        // si se da este caso ya descartas
        /*
         * o=1 c=1 n=5 k=4
         *
         * si c>o -> 0 1 1 - - no nos interesa
         * si k-c>n-o -> 0 0 1 - - - no nos interesa
         */
        if (c>o or k-c>n-o) return ;
        // zona escribir
        if (k==n) {
            if (c==o) {
                cout << v[0];
                for (int i=1; i<n; i++) cout << ' '<< v[i];
                cout << endl;
            }
            // caso c<o
        }

        // caso recursivo
        else {
        v[k]=0;
        hacer(v,n,o,k+1,c);
        v[k]=1;
        hacer(v,n,o,k+1,c+1);
}
}

int main() {
    int n;
    int o;
    cin >> n >> o;
    vector <int> v(n);
    hacer(v,n,o,0,0);
}
