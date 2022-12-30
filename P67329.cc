#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<char> v= {'A','C','G','T'};
int n;

void back(int k, string s) {
    if(k==n) cout << s << endl;
    else {
        for(int i=0; i<4; i++) {
            s[k]=v[i];
            back(k+1,s);
        }
    }
}

int main() {
    cin >> n;
    string s(n,'.');
    back(0,s);
}
