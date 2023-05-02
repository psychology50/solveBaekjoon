#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

int l, c; // l: 암호 길이, c: 알파벳 개수
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
vector<char> alpha;

void dfs(int idx, int depth, string str) {
    if (depth == l) {
        int cnt = 0;
        for (int idx = 0; idx < str.size(); idx++) for (int j=0; j<5; j++) if (str[idx] == vowel[j]) {
           cnt++;
           break;
        }
        if (cnt >= 1 && cnt <= l-2) cout << str << endl;
        return;
    }
    for (int i = idx; i < c; i++) {
        dfs(i+1, depth+1, str+alpha[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> l >> c;

    // 서로 다른 L개의 알파엣 소문자 구성
    // 최소 한 개의 모음(a, e, i, o, u)과 두 개의 자음으로 구성
    // 알파벳은 오름차순으로 배열 -> abc(o), bac(x)
    // 조교들이 암호로 사용했을 법한 문자의 종류는 C가지
    // C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호 전부 출력
 
    for (int i = 0; i < c; i++) {
        char tmp; cin >> tmp;
        alpha.push_back(tmp);
    }
    sort(alpha.begin(), alpha.end());
    
    dfs(0, 0, "");
    
    return 0;
}