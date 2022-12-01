#include <iostream>
#include <map>
using namespace std;


int evaluate (int x, int y, int n) {
        map <int,int> m;
        int i=0;
        while (m.find(n)==m.end()) {
            // es decir que esta dentro
            m.insert(make_pair(n,i));
            i++;
            if (n%2==0) {
                // es parell
                n = n/2 + x;
            }
            else n=3*n + y;
            if (n>100000000) return n;
        }
        auto it = m.find(n);
        int number = it->second;
        return i-number;
}

int main() {
    int x, y;
    int n;
    while (cin >> x >> y >> n) {
        cout << evaluate (x,y,n) << endl;

    }
}
