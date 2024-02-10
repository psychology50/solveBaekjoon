#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void Solve() {
    int G1,S1,B1; cin >> G1 >> S1 >> B1;
    int G2,S2,B2; cin >> G2 >> S2 >> B2;

    int answer = 0;
    
    while(S1-1>=S2 && B1<B2) {
        S1--;
        B1+=9;
        answer++;
    }
    while(G1-1>=G2 && S1<S2) {
        G1--;
        S1+=9;
        answer++;
    }
    while(S1-11>=S2 && G1<G2) {
        S1-=11;
        G1++;
        answer++;
    }
    while(B1-11>=B2 && S1<S2) {
        B1-=11;
        S1++;
        answer++;
    }
    while(B1<B2) {
        S1--;
        B1+=9;
        answer++;
    }
    while(S1<S2) {
        G1--;
        S1+=9;
        answer++;
    }
    while(G1<G2) {
        S1-=11;
        G1++;
        answer++;
    }
    while(S1<S2) {
        B1-=11;
        S1++;
        answer++;
    }
    if(G1>=G2 && S1>=S2 && B1>=B2) cout << answer;
    else cout << -1;
    
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}