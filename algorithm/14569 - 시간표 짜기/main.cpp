#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n, m;
vvi subjects, students;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; subjects.resize(n);
    for (int i=0, k, t; i<n; ++i) {
        cin >> k;
        for (int j=0; j<k; ++j) {
            cin >> t; subjects[i].push_back(t);
        }
    }
    cin >> m; students.resize(m);
    for (int i=0, k, t; i<m; ++i) {
        cin >> k;
        for (int j=0; j<k; ++j) {
            cin >> t; students[i].push_back(t);
        }
    }

    for (vi& sub : subjects) {
        int sz = sub.size(), cnt = 0;
    }

    return 0;
}