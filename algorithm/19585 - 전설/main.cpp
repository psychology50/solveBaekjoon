#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct Node;
map<char, Node*> str;

struct Node {
    char ch;
    bool end;

    Node() { end = false; }

    void add(const char* c) {
        if (! *c) {
            end = true;
            return;
        }
        
        str[*c] -> add(c + 1);
    }

    bool find(const char* c) {
        
    }
};

Node* color = new Node();
Node* name = new Node();


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    str.clear();

    int c, n; cin >> c >> n;
    for (int i = 0; i < c; i++) {
        string s; cin >> s;
        color -> add(s.c_str());
    }
    for (int j = 0; j < n; j++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        name -> add(s.c_str());
    }

    return 0;
}