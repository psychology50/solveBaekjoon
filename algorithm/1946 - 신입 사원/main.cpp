#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 987654321

using namespace std;
int t, n;
typedef struct person {
    int document, interview;
} person;
vector<person> people;
int cnt;

bool cmp(person& a, person& b) {
    return a.document < b.document;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;

    while (t--) {
        cin >> n;

        people.resize(n); cnt = 0;
        for (int i = 0; i < n; ++i) {
            int doc, inter; cin >> doc >> inter;
            people[i] = {doc, inter};
        }

        sort(people.begin(), people.end(), cmp);
        
        int maxInV = MAX;
        for (person& p : people) {
            if (p.document == 1 || p.interview < maxInV) {
                ++cnt;
                maxInV = p.interview;
                continue;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}