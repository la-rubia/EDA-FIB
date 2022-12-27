#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct roca {
    double x;
    double y;
    double r;
};

double dist (roca a, roca b) {
    double res = sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2)) - a.r - b.r;
    return res;
}

int zamburguesas (const vector<roca>& r, double d) {
    int n = r.size();
    vector<bool> rv(n,false);
    vector<int> s (n,0);

    queue<int> q;
    q.push(0);
    rv[0]=true;

    while (q.size()>0) {
        int ract = q.front();
        q.pop();
        // trabajaremos sobre la actual

        // cas recursivo: hemos llegado al final
        if (ract == n-1) return s[ract];
        else {
            for (int i=0; i<n; i++) {
                if (i!=ract and not rv[i] and dist(r[i],r[ract])<=d) {
                    s[i] = s[ract]+1;
                    q.push(i);
                    rv[i]=true;
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    double d;
    while (cin >> n >> d) {
        vector<roca> r(n);
        for (int i=0; i<n; i++) {
            cin >> r[i].x >> r[i].y >> r[i].r;
        }

        int res = zamburguesas(r,d);

        if (res < 0) cout << "Xof!" << endl;
        else cout << res << endl;
    }
}
