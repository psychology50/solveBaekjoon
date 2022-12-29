#include <iostream>
#include <cstdio>
#include <vector>

#define ll long long

using namespace std;
typedef pair<int, int> p;

ll Answer;

void swap(vector<p> &arr, int a, int b) {
    p tmp = arr[b];
    arr[b] = arr[a];
    arr[a] = tmp;
}

void quick_sort(vector<p> &arr, int start, int end) {
    if (start >= end) return;

    int pivot = start;
    int i = pivot + 1, j = end;

    while (i <= j) {
        while (i <= end && (arr[i].second <= arr[pivot].second)) i++;
        while (j > start && (arr[j].second >= arr[pivot].second)) j--;

        if (i > j) {
            swap(arr, pivot, j);
        } else if (i < j) {
            swap(arr, i, j);
        }
    }

    quick_sort(arr, start, j - 1);
    quick_sort(arr, j + 1, end);
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
        vector<p> ant;

        for (int i=0; i<n; i++) {
            int idx; cin >> idx;
            origin.push_back(idx);
            ant.push_back({idx, 0});
        }
        for (int i=0; i<n; i++) {
            int input_val; cin >> input_val;
            ant[i].second = input_val;
        }

        quick_sort(ant, 0, n-1);

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