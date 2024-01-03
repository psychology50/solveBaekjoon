#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k;
int treeSz;
int arr[1050];
vector<int> tree[10];

void solution(int s, int e, int d) {
	if (d >= k)
		return;

	if (s == e) { //리프 노드 
		tree[d].push_back(arr[s]);
		return;
	}

	int m = (s + e) / 2;

	if (m < 0 || m >= treeSz)
		return;

	tree[d].push_back(arr[m]);
	solution(s, m - 1, d + 1);
	solution(m + 1, e, d + 1);

}

int main(void) {

	cin >> k;

	treeSz = pow(2, k) - 1;

	for (int i = 0; i < treeSz; i++) {
		cin >> arr[i];
	}

	solution(0, treeSz - 1, 0);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}