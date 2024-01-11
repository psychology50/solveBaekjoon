#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int A, B, C;
set<int> results;
bool visited[201][201][201];

void recur(int a, int b, int c) {
    if (visited[a][b][c]) return;
    visited[a][b][c] = true;
    if (a == 0) results.insert(c);

        recur(
            (a > B-b) ? a-(B-b) : 0,
            (a > B-b) ? B : a+b,
            c
        );
        recur(
            (a > C-c) ? a-(C-c) : 0,
            b,
            (a > C-c) ? C : a+c
        );
        recur(
            (b > A-a) ? A : b+a,
            (b > A-a) ? b-(A-a) : 0,
            c
        );
        recur(
            a,
            (b > C-c) ? b-(C-c) : 0,
            (b > C-c) ? C : b+c
        );
        recur(
            (c > A-a) ? A : c+a,
            b,
            (c > A-a) ? c-(A-a) : 0
        );
        recur(
            a,
            (c > B-b) ? B : c+b,
            (c > B-b) ? c-(B-b) : 0
        );
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> A >> B >> C;

    recur(0, 0, C);

    for (const auto& result : results) {cout << result << " ";}
    return 0;
}