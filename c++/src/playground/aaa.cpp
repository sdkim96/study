#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int getOrDefault(unordered_map<string, int>& m, const string &key, int defaultValue) {
    auto it = m.find(key);
    return it != m.end()? it->second : defaultValue;
};

int main() {

    set<int> s;
    vector<int> v;

    set<string> s2;

    unordered_map<string, int> m;

    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;

    int mValue = getOrDefault(m, "a", 0);

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);


    s2.insert("a");
    s2.insert("b");
    s2.insert("c");
    s2.insert("a");

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

}