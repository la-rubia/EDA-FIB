#include <iostream>
#include <vector>
using namespace std;

bool dico(int x, const vector<int>& v, int e, int d) {
    if(e>d) return false;
    int m = (e+d)/2;
    if(v[m]>x) return dico(x,v,e,m-1);
    else if(v[m]<x) return dico(x,v,m+1,d);
    return true;
}


bool search(int x, const vector<int>& v, int e, int d) {
    if(e+1==d) return v[e]==x or v[d]==x;
    else {
        int m = (d+e)/2;
        if(v[m]>=v[e]) {
            // estamos en el caso de todo para arriba
            if(v[e]<=x and v[m]>=x) return dico(x,v,e,m);
            else return search(x,v,m,d);
        }
        else {
            if(v[m]<=x and v[d]>=x) return dico(x,v,m,d);
            else return search(x,v,e,m);
        }
    }
}

bool search(int x, const vector<int>& v) {
    return search(x,v,0,v.size()-1);
}



