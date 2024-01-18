#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k, n;

string matchLadder(string pre, string target) {
    string res;

    for (int i=0; i<k-1; ++i) {
        if (pre[i] == target[i]) res += '*';
        else if (pre[i] == target[i+1]) {
            res += (i != k-2) ? "-*" : "-";
            ++i;
        }
        else {
            string cannot;
            for (int i=0; i<k-1; ++i) cannot += 'x';
            return cannot;
        }
    }
    return res;
}

void undergo(string& people, string& ladder) {
    for (int i=0; i<k-1; ++i) {
        if (ladder[i] == '*') continue;
        char tmp = people[i];
        people[i] = people[i+1];
        people[i+1] = tmp;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string pre, target;
    cin >> k >> n >> target;

    for (int i=0; i<k; ++i) pre += (65 + i);

    int unknown;
    bool flag = false;
    vector<string> ladders;
    for (int i = 0; i < n; ++i) {
        string now; cin >> now;

        if (flag) ladders.push_back(now);

        if (now[0] == '?') {
            unknown = i;
            flag = true;
            continue;
        }

        if (!flag) undergo(pre, now);
    }

    for (int idx = ladders.size() - 1; idx >= 0; --idx) {
        undergo(target, ladders[idx]);
    }

    cout << matchLadder(pre, target);

    return 0;
}