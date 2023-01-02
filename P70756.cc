#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VI = vector<int>;

int n,p;
VS paraules;
VI assign;

void write() {
//     for(int i=0; i<n; i++) cout << assign[i] << ' ';
//     cout << endl;

    for(int i=0; i<p; i++) {
        cout << "subconjunt " << i+1 << ": {";
        bool primer=true;
        for(int j=0; j<n; j++) {
            if(assign[j]==i) {
                if(primer) {
                    primer=false;
                    cout << paraules[j];
                }
                else cout <<','<< paraules[j];
            }
        }
        cout << '}'<<endl;
    }
    cout << endl;
}

void back(int k) {
    if(k==n) {
        write();
    }
    else {
        for(int i=0; i<p; i++) {
            assign[k]=i;
            back(k+1);
        }
    }
}

int main() {
    cin >> n;
    paraules = VS(n);
    assign = VI(n,-1);
    for(int i=0; i<n; i++) cin >>paraules[i];
    cin >> p;
    back(0);


}
