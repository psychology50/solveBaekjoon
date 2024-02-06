#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 55
#define INF 1e9

using namespace std;
using pii = pair<int, int>;

int N, M;
int MAP_Number[MAX][MAX];
int MAP[MAX][MAX];
int Bead_Number[MAX * MAX];
int tmp[MAX * MAX];
pii Shark;
bool visited[MAX][MAX];
int moveY[4] = { 0,1,0,-1 }, moveX[4] = { -1,0,1,0 };
int BlizzardY[5] = { 0,-1,1,0,0 }, BlizzardX[5] = { 0,0,0,-1,1 };
int Bombed_Bead[4] = { 0, };

void init() {
	Shark = make_pair((N + 1) / 2, (N + 1) / 2);
	int Dir = 0, Len = 1, Cnt = 0, Number = 1;
	while (1) {
		for (int i = 0; i < Len; i++) {
			int Y = Shark.first;
			int X = Shark.second;
			int nextY = Y + moveY[Dir];
			int nextX = X + moveX[Dir];
			MAP_Number[nextY][nextX] = Number;
			Number++;
			Shark = make_pair(nextY, nextX);
		}
		Dir++;
		if (Dir == 4) {
			Dir = 0;
		}
		Cnt++;
		if (Cnt == 2) {
			Cnt = 0;
			Len++;
		}
		if (Len == N) {
			for (int i = 0; i < Len; i++) {
				int Y = Shark.first;
				int X = Shark.second;
				int nextY = Y + moveY[Dir];
				int nextX = X + moveX[Dir];
				MAP_Number[nextY][nextX] = Number;
				Number++;
				Shark = make_pair(nextY, nextX);
			}
			break;
		}
	};
	Shark = make_pair((N + 1) / 2, (N + 1) / 2);
}

void Blizzard_Magic(int Dir, int Len) {
	int Y = Shark.first;
	int X = Shark.second;
	for (int i = 1; i <= Len; i++) {
		int nextY = Y + BlizzardY[Dir];
		int nextX = X + BlizzardX[Dir];
		MAP[nextY][nextX] = 0;
		Bead_Number[MAP_Number[nextY][nextX]] = 0;
		Y = nextY;
		X = nextX;
	}
}

void Bead_Moving() {
	for (int i = 1; i < (N * N); i++) {
		if (Bead_Number[i] == 0) {
			for (int j = (i + 1); j < (N * N); j++) {
				if (Bead_Number[j] != 0) {
					Bead_Number[i] = Bead_Number[j];
					Bead_Number[j] = 0;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = Bead_Number[MAP_Number[i][j]];
		}
	}
}

bool Bead_Explosion() {
	bool Flag = false;
	int Start = -1;
	int Len = 0;
	for (int i = 1; i < (N * N); i++) {
		if (Bead_Number[i] == 0) {
			break;
		}
		if (Start == -1) {
			Start = i;
			Len = 1;
		}
		else {
			if (Bead_Number[i] == Bead_Number[Start]) {
				Len++;
			}
			else {
				if (Len >= 4) {
					Flag = true;
					for (int j = Start; j < i; j++) {
						Bombed_Bead[Bead_Number[j]]++;
						Bead_Number[j] = 0;
					}
				}
				Start = i;
				Len = 1;
			}
		}
	}
	if ((Start != -1) && (Len >= 4)) {
		Flag = true;
		for (int i = Start; i < (N * N); i++) {
			Bombed_Bead[Bead_Number[i]]++;
			Bead_Number[i] = 0;
		}
	}
	return Flag;
}

void Make_Group() {
	int A = 0, B = -1;
	for (int i = 0; i < (MAX * MAX); i++) {
		tmp[i] = 0;
	}
	int IDX = 1;
	bool isFull = false;
	for (int i = 1; i < (N * N); i++) {
		if (Bead_Number[i] == 0) {
			continue;
		}
		if (B == -1) {
			B = Bead_Number[i];
			A = 1;
		}
		else {
			if (Bead_Number[i] == B) {
				A++;
			}
			else {
				if (!isFull) {
					tmp[IDX++] = A;
				}
				if (IDX == (MAX * MAX)) {
					isFull = true;
				}
				if (!isFull) {
					tmp[IDX++] = B;
				}
				if (IDX == (MAX * MAX)) {
					isFull = true;
				}
				B = Bead_Number[i];
				A = 1;
			}
		}
	}
	if (B != -1) {
		if (!isFull) {
			tmp[IDX++] = A;
		}
		if (IDX == (MAX * MAX)) {
			isFull = true;
		}
		if (!isFull) {
			tmp[IDX++] = B;
		}
	}
	for (int i = 1; i < (N * N); i++) {
		Bead_Number[i] = tmp[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = Bead_Number[MAP_Number[i][j]];
		}
	}
}

int Solution() {
	return (Bombed_Bead[1] + (2 * Bombed_Bead[2]) + (3 * Bombed_Bead[3]));
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	init();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			Bead_Number[MAP_Number[i][j]] = MAP[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int D, S;
		cin >> D >> S;
		Blizzard_Magic(D, S);
		Bead_Moving();
		while (1) {
			bool isExplosion = Bead_Explosion();
			Bead_Moving();
			if (!isExplosion) {
				break;
			}
		};
		Make_Group();
	}
	cout << Solution();

	return 0;
}