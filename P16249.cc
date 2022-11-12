#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

using VS=vector<string>;

int n,l;

int main() {
    while (cin >> n) {
        map<string,pair<VS,int>> m;
        for (int i=0; i<n; i++){
            string s; cin >> s;
            VS empty;
            m[s]={empty,0};
        }
        cin >> l;
        for (int i=0; i<l; i++) {
            string x, y; cin >> x >> y;
            m[x].first.push_back(y);
            m[y].second++;
        }

        set<string> s;
        for (auto it=m.begin(); it!=m.end(); it++) {
            if((it->second).second==0) s.insert(it->first);
        }
        if (s.empty()) cout << "NO VALID ORDERING" << endl;
        else {
            string f="";
            while (not s.empty()) {
                auto it=s.begin(); string paraula=*it; s.erase(it); f+=paraula;

                auto it2=m.find(paraula);
                VS v = (it2->second).first;
                for (int i=0; i<v.size(); i++) {
                    string k=v[i];
                    if (--m[k].second==0) s.insert(k);
                }
            }
            bool found=false;
            for (auto it=m.begin(); it!=m.end(); it++) {
                if ((it->second).second!=0) found=true;
            }
            if (found) cout << "NO VALID ORDERING" <<endl;
            else cout << f << endl;
        }
    }
}
