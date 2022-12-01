#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> s;
    string w;
    cin >> w;
    auto it = s.begin();
    while (w!="END") {
        s.insert(w);
        int n = s.size();
        if (n==1) it = s.find(w);
        else if (n%2==0 and w<*it) it--;
        else if (n%2!=0 and w>*it) ++it;
        cout << *it << endl;
        cin >> w;
    }
}

