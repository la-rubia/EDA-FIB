#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> d;

bool ok(int x) {
    for(int y: d) {
        if(x%y==0) return false;
    }
    return true;
}





void back(int k,int r) {
    if(k==n) cout << r << endl;
    else {
        for(int i=0; i<10; i++) {
            int y=r*10+i;
            if(ok(y)) back(k+1,y);
        }
    }
}

int main() {
    while (cin >> n >> m) {
        d = vector<int>(m);
        for (int i=0; i<m; i++) cin >> d[i];
        back(0,0);
        cout << "----------"<<endl;
    }
}
