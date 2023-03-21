#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    bool end;

    Node() { end = false; }

    void insert(const char* c) {
        if (! *c) {
            end = true;
            return;
        }


    }

    bool find(const char* c) {

    }
};


Node* color = new Node();
Node* name = new Node();
map<char, Node*> chr;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int c, n; cin >> c >> n;
    for (int i = 0; i < c; i++) {
        string s; cin >> s;
        color -> insert(s.c_str());
    }
    for (int j = 0; j < n; j++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        name -> insert(s.c_str());
    }

    return 0;
}