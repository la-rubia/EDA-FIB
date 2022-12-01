#include <iostream>
#include <queue>
using namespace std;

void evaluation(const priority_queue<int, vector<int>, greater<int>>& q, int max, double suma, double n){
    if (q.empty()) cout << "no elements" << endl;
    else {
    double average = suma/n;
    int min=q.top();
    cout << "minimum: " << min << ", maximum: " << max << ", average: " << average << endl;
    }
}
/*
void write (const priority_queue<int, vector<int>, greater<int>>& q) {
    auto p=q;
    while (not p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
}
*/

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    string command;
    double sum=0.0000;
    double n=0;
    int max;

    priority_queue<int,vector<int>,greater<int>> q;
    while (cin >> command) {
        if (command=="number") {

            int x; cin >> x;
            if (q.empty()) max=x;
            if (x>max) max=x;
            q.push(x);
            sum+=x;
            n++;
            evaluation(q,max,sum,n);


         //   write(q);


        }
        else {
            if (not q.empty()) {
                int x=q.top();
                q.pop();
                n--;
                sum-=x;
            }
            evaluation(q,max,sum,n);

         //   write(q);

        }
    }
}
