#include <iostream>
#include <queue>
using namespace std;


int main() {
    char op;
    priority_queue<int> q;
    while (cin >> op) {
        if (op=='S') {
            int x; cin >> x;
            q.push(x);
        }
        else if (op=='A') {
            if (not q.empty()) cout << q.top() << endl;
            else cout << "error!" << endl;
        }
        else if (op=='R') {
            if (not q.empty()) q.pop();
            else cout << "error!" << endl;
        }
        else if (op=='I') {
            int x; cin >> x;
            if (not q.empty()) {
                int n = q.top();
                q.pop();
                q.push(n+x);
            }
            else cout << "error!" << endl;
        }
        else {
            int x; cin >> x;
            if (not q.empty()) {
                int n = q.top();
                q.pop();
                q.push(n-x);
            }
            else cout << "error!" << endl;
        }
    }
}
