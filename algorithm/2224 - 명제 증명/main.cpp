#include <iostream>
#include <string>

using namespace std;

int n;
bool cache[58][58];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		string input;
		getline(cin, input);
		if (input[0] == input[input.length() - 1]) continue;
		if (cache[input[0] - 'A'][input[input.length() - 1] - 'A']) continue;
		cnt++;
		cache[input[0] - 'A'][input[input.length() - 1] - 'A'] = true;
	}

	for (int k = 0; k < 58; k++) {
		for (int i = 0; i < 58; i++) {
			for (int j = 0; j < 58; j++) {
				if (cache[i][j] || i==j) continue;
				cache[i][j] = cache[i][k] && cache[k][j];
				if (cache[i][j]) cnt++;
			}
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < 58; i++) {
		for (int j = 0; j < 58; j++) {
			if (cache[i][j]) {
				cout << (char)(i + 'A') << " => " << (char)(j + 'A')<<'\n';
			}
		}
	}
	return 0;
}