#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>

#define endl "\n"
using namespace std;

int check[2001];
struct Node {
    map<char, Node*> str;
    bool end;

    Node() { 
        end = false; 
        str.clear();
    }

    void insert(const char* c) {
        if (! *c) {
            end = true;
            return;
        }
        int now = *c - 'a';
        if (!str[now]) { str[now] = new Node(); }
        str[now] -> insert(c + 1);
    }

    void find(const char* c, int idx, bool flag) { // flag -> 1: color, 0: name
        if (end) check[idx]++;
        if (! *c) return;
        int now = *c - 'a';
        if (!str[now]) return;
        str[now] -> find(c+1, flag ? idx+1 : idx-1, flag);
    }
};

Node* color = new Node;
Node* name = new Node;

void input_node() {
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
}

void solution() {
    int q; cin >> q;

    while (q--) {
        string s; cin >> s;
        memset(check, 0, sizeof(check));
        
        color -> find(s.c_str(), 0, true);
        reverse(s.begin(), s.end());
        name -> find(s.c_str(), s.size(), false);

        bool ans = false;
        for (int i = 0; i < s.size(); i++) if (check[i] == 2) {ans = true; break;}
        cout << ((ans) ? "Yes" : "No") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input_node();
    solution();

    return 0;
}