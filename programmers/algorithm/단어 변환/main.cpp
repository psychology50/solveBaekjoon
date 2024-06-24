#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

#define MAX 1e9

using namespace std;
string sink;
int ret = MAX, sz;
map<string, bool> visited;

void dfs(string str, int cnt, vector<string>& words) {
    if (str == sink) {
        ret = min(ret, cnt);
        return;
    }
    if (visited[str]) return;
    visited[str] = true;
    
    for (string& word : words) {
        if (visited[word]) continue;
        for (int idx=0; idx<sz; ++idx) {
            if (str.substr(0, idx) == word.substr(0, idx) && str.substr(idx+1, sz-1) == word.substr(idx+1, sz-1)) {
                dfs(word, cnt+1, words);
                break;
            }
        }
    }
    dfs(str, cnt, words);
}

int solution(string begin, string target, vector<string> words) {
    sink = target, sz = begin.length();
    
    bool isPresent = false;
    for (string& word : words) {
        if (target == word) isPresent = true;
        visited[word] = false;
    }
    if (!isPresent) return 0;
    
    dfs(begin, 0, words);
    return (ret == MAX) ? 0 : ret;
}