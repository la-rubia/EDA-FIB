#include <iostream>
#include <vector>
using namespace std;


bool dico(int x, const vector<int>& v, int e, int d) {
//     cout << "dico " << e << ' ' << d << ' ';
    if(e>=d) return v[e]==x;
    else {
        int m = (e+d)/2;
//         cout << m << endl;
        if(v[m]>x) return dico(x,v,e,m-1);
        else if(v[m]<x) return dico(x,v,m+1,d);
        return true;
    }
}

bool inv_dico(int x, const vector<int>& v, int e, int d) {
//     cout << "inv_dico " << e <<' ' << d << ' ';
    if(e>=d) return v[e]==x;
    else {
        int m = (e+d)/2;
//         cout << m << endl;
        if(v[m]>x) return inv_dico(x,v,m+1,d);
        else if(v[m]<x) return inv_dico(x,v,e,m-1);
        return true;
    }
}


int p(const vector<int>& v, int e, int d) {
    if(e+1>=d){
        if(v[e]<v[d]) return d;
        else return e;
    }
    else {
        int m=(e+d)/2;
        if(v[m-1]>v[m]) return p(v,e,m-1);
        if(v[m+1]>v[m]) return p(v,m+1,d);
        return m;
    }
}

bool search(int x, const vector<int>& v) {
    int pic = p(v,0,v.size()-1);
    return dico(x,v,0,pic) or inv_dico(x,v,pic,v.size()-1);
}


int main() {
    vector<int> v = {8,9,7,6,5,4,3,2,1};
    int x; while(cin >> x) {
    if(search(x,v)) cout << "yes" << endl;
    else cout << "no" << endl;
    }
}
