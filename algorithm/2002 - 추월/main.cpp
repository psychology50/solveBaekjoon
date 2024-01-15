#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int n;
unordered_map<string, int> cars;
bool visited[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string car; cin >> car;
        cars.insert({car, i});
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        string car; cin >> car;
        for (int pre=0; pre<cars[car]; ++pre) {
            if (!visited[pre]) {
                ++res;
                break;
            }
        }
        visited[cars[car]] = true;
    }

    cout << res;
    return 0;
}