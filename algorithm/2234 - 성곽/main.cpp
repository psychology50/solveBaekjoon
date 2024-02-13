#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int board[50][50];
int d[50][50];
int rooms[50 * 50];

// 서 북 동 남
const int dy[4] = { 0,-1,0,1 };
const int dx[4] = { -1,0,1,0};
int solve(int y, int x, int roomNum)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	d[y][x] = roomNum;
	int cnt = 0;
	while (!q.empty())
	{
		y = q.front().first, x = q.front().second; q.pop();
		++cnt;
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (d[ny][nx] != 0) continue;
			if (board[y][x] & (1 << i)) continue;
			
			d[ny][nx] = roomNum; q.push({ ny,nx });
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for(int i=0; i<m; ++i) for (int j = 0; j < n; ++j) cin >> board[i][j];

	int num = 0;
	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (d[i][j] == 0) {rooms[++num] = solve(i, j, num);}
	cout << num << "\n";
	cout << *max_element(rooms+1, rooms+num+1) << "\n";

	int ret = 0;
	for(int i=0; i<m; ++i) for (int j = 0; j < n; ++j) {
		int y = i, x = j;
		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (d[ny][nx] == d[y][x]) continue;
			if (board[y][x] & (1 << k)) {
				ret = max(ret, rooms[d[ny][nx]] + rooms[d[y][x]]);
			}
		}
	}
	cout << ret << "\n";
	return 0;
}