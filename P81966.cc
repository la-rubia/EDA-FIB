P81966#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 2 3 x 5 6


int position(double x, const vector<double>& v, int left, int right){

    if (left>right) return -1;
    int pos = (left+right)/2;
    if (v[pos]<x) return position(x,v,pos+1, right);
    if (v[pos]>x) return position(x,v,left,pos-1);
    return pos;
}
