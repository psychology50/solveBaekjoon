#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> info(n);
    vector<int> cache(k+1);

    for (int i=0; i<n; i++)
        cin >> info[i];

    cache[0] = 1;
    for (int i=0; i<n; i++)
        for (int j=info[i]; j <= k; j++)
            cache[j] += cache[j - info[i]];

    cout << cache[k] << endl;
    return 0;
}