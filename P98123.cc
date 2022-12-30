#include <iostream>
#include <set>
using namespace std;

void imprimir(const set<long int>& s) {
    for(long int x: s) cout << x << ' ';
    cout << endl;

}

int main() {
    int n; cin >> n;
    set<long int> bag,cave;
    string command;
    long int x;
    long int suma=0;
    while (cin >> command and cin >> x) {
        if(command=="deixar") {
            if (int(bag.size())<n) {
                bag.insert(x);
                suma+=x;
            }
            else {
                auto it = bag.begin();
                if(*it<x) {
                    suma+=x;
                    suma-=*it;

                    cave.insert(*it);
                    bag.erase(it);
                    bag.insert(x);

                }
                else cave.insert(x);
            }

        }
        else {
            auto it = cave.find(x);
            if (it!=cave.end()) cave.erase(it);
            else {
                it = bag.find(x);
                bag.erase(it);
                suma-=x;
                if(int(cave.size())!=0) {
                    it=cave.end(); it--;
                    bag.insert(*it);
                    suma+=*it;
                    cave.erase(it);

                }
            }
        }
        /*cout << "la bag: "<< endl;
        imprimir(bag);
        cout << "la cave: " << endl;
        imprimir(cave);
        cout <<"la suma: "<<endl;*/
        cout << suma << endl;
//         cout << endl;

    }

}
