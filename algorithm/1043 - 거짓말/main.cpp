#include <iostream>
#include <vector>

#define MAX 55
#define endl "\n"

using namespace std;

int n, m;
bool isKnown[MAX] = {false, };
vector<int> party[MAX];

void init();
void findWillKnown();
int canLie();

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    init();
    findWillKnown();
    cout << canLie() << endl;

    return 0;
}

void init() {
    cin >> n >> m;

    int isKnowCount; cin >> isKnowCount;
    for (int i=0; i<isKnowCount; ++i) {
        int peopleNum; cin >> peopleNum;
        isKnown[peopleNum] = true;
    }

    for (int day=0; day<m; ++day) {
        int num; cin >> num;
        for (int j = 0; j < num; ++j) {
            int tmp; cin >> tmp;
            party[day].push_back(tmp);
        }
    }
}

void findWillKnown() {
    for (int day=0; day<m; ++day) {
        bool flag = false;

        for (int people : party[day]) {
            if (isKnown[people]) {
                flag = true;
                break;
            }
        }
        
        if (flag) {
            for (auto people : party[day]) {
                isKnown[people] = true;
            }
        }
    }
}

bool isValid(int day) {
    for (auto people : party[day]) {
        if (isKnown[people]) return false;
    }
    return true;
}

int canLie() {
    int cnt = 0;

    for (int day=0; day<m; ++day)
        if (isValid(day))
            ++cnt;

    return cnt;
}