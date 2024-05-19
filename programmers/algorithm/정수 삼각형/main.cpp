#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int line=triangle.size() - 1; line > 0; --line) {
        for (int i=0; i<triangle[line].size() - 1; ++i) {
            triangle[line-1][i] += max(triangle[line][i], triangle[line][i+1]);
        }
    }
    
    return triangle[0][0];
}