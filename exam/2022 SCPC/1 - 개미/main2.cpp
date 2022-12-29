#include <iostream>
#include <cstdio>
#include <vector>

#define ll long long

using namespace std;
typedef pair<int, int> p;

ll Answer;
vector<p> ant, tmp;

void merge(vector<p> &arr, int left, int mid, int right) {
    int i, j, k; i = left; j = mid + 1; k = left;

    while (i <= mid && j <= right) {
        if (arr[i].second <= arr[j].second)
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= right) {
        tmp[k++] = arr[j++];
    }

    for (int idx = left; idx <= right; idx++) arr[idx] = tmp[idx];
}

void merge_sort(vector<p> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, test_case;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = 0;
		int n; cin >> n;

        vector<int> origin;

        for (int i=0; i<n; i++) {
            int idx; cin >> idx;
            origin.push_back(idx);
            ant.push_back({idx, 0});
            tmp.push_back({0, 0});
        }
        for (int i=0; i<n; i++) {
            int input_val; cin >> input_val;
            ant[i].second = input_val;
        }

        merge_sort(ant, 0, n-1);

        for (int i=0; i<n; i++) {
            if (ant[i].first != origin[i]) {
                Answer += abs((ll)(ant[i].first) - (ll)(origin[i]));
            }
        }
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;

        ant.clear();
        vector<p>().swap(ant);
	}
	return 0;
}