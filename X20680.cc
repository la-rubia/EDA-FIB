#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,c;

bool ok(int k, char l, string s) {
    int i=k-1; // 0 1 2 3 k-1
    int f = k-1-c;
    int count=0;
    while(i>=0 and i>f) {
        if(s[i]==l) count++;
        i--;
    }
    return count<c;
}

void back(int k, string s) {
    if(k==n) cout << s << endl;
    else {
        if(ok(k,'x',s)){
            s[k]='x';
            back(k+1,s);
        }
        if(ok(k,'y',s)) {
            s[k]='y';
            back(k+1,s);
        }
        if(ok(k,'z',s)) {
            s[k]='z';
            back(k+1,s);
        }
    }
}

int main() {
    while(cin >> n >> c) {
        string s(n,'.');
        back(0,s);
        cout << "--------------------" << endl;
    }
}
