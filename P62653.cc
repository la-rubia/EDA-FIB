#include <iostream>
#include <string>
#include <queue>
using namespace std;

string s;


/*
 * usaremos una pila, los que estén en top se quedan antes con la entrada, taraaaan
 *
 * si a tiene que ir abajo = true
 * si a tiene que ir arriba = false
 */
struct cmp {
    bool operator() (string a, string b) {
        if (a.length()==b.length()) {
            string w="";
            for (int i=0; i<a.length(); i++) {
                w+=s[i];
            }
            if (a==w) return false;
            if (b==w) return true;
            if (a<b) {
                if (w>a and w<b) return true;
                return false;
            }
            else {
                if (w<a and w>b) return false;
                return true;
            }
        }
        else return a.length() > b.length();
    }
};

int main() {
    while (cin >> s) {
        char c;
        priority_queue<string,vector<string>, cmp> solicitudes;
        int ct=0;
        while (cin >> c and c!='E') {
            if (c=='S') {
                string a;
                cin >> a;
                solicitudes.push(a);
            }
            else if (c=='T') {
                ct++;
            }
            while (ct>0 and (not solicitudes.empty())) {
                cout << solicitudes.top() << endl;
                solicitudes.pop();
                ct--;
            }
        }
        cout << ct << " ticket(s) left" << endl;
        cout << solicitudes.size() << " supporter(s) with no ticket" << endl;
        cout << endl;
    }
}
