
#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
#include <string>



using namespace std;


bool cmp1(string a, string b) {
    if (a.size()!=b.size())return a.size()<b.size();
    else return a<b;
}
int main()
{

    string word;
    int counter=1;
    while (word!="QUIT"){
            set<string> has;
            unordered_set<string> had;
        while (cin >> word and word!="END" and word!="QUIT") {
            unordered_set<string>::iterator it;
            // comprobaciones en el had
            it=had.find(word);
            if (it!=had.end()){
                // si está en la lista de antes borralo -> lo pondremos en la de sí está
                had.erase(it);
            }
            // comprobaciones en el has
            set<string>:: iterator it1;
            it1=has.find(word);
            if (it1!=has.end()){
                // si sí está en la lista -> borralo y ponlo en la de estaba
                  has.erase(word);
                had.insert(word);
                
            }
            else {
                  has.insert(word);
            
            }

        }
    	
    	if (counter>1) cout << endl;
        cout << "GAME #"<< counter << endl;
        cout << "HAS:"<<endl;
        set<string>:: iterator i;
        for (i=has.begin();i!=has.end();i++) {
            cout << *i << endl;
        }
        cout << endl;
        cout << "HAD:" << endl;
        vector<string>x(had.begin(),had.end());
        sort(x.begin(),x.end(),cmp1);
        vector<string>:: iterator j;
        for (j=x.begin();j!=x.end();j++) {
            cout << *j<< endl;
        }

        counter++;  
    }
}

