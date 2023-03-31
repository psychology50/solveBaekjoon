#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string L, R; cin >> L >> R;
    int Lsize = L.length(), Rsize = R.length();
    int ans = 0;
    if (Lsize == Rsize) for (int i = 0; i < Lsize; i++) {
        if (L[i] != R[i]) break;
        if (L[i] == '8') ans++;
    }

    cout << ans << "\n";
    return 0;
}
