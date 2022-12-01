#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin,line)) {
        istringstream ss(line);
        int x;
        set<int> sequence;

        while (ss>>x) {
            sequence.insert(x);
        }
        int sum = 0;
        if (not sequence.empty()) {
            sum = 1;
            auto it =sequence.begin();
            int n = *it;
            it++;
            for (; it!=sequence.end(); it++) {
                if (n%2==0 and *it%2!=0) sum++;
                else if (n%2!=0 and *it%2==0) sum++;
                n=*it;
            }
        }
        cout << sum << endl;
    }
}
