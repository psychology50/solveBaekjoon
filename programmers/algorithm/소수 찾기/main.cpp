#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>

#define MAX 10000000

using namespace std;
bool eratostenes[MAX];

bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int i=2; i<=sqrt(n); ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> ret;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        string tmp;
        for (int i=0; i<numbers.size(); ++i) {
            tmp += numbers[i];
            if (isPrime(stoi(tmp))) ret.insert(stoi(tmp));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return ret.size();
}