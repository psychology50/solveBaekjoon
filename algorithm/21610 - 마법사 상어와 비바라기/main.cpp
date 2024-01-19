#include <iostream>
#include <cstring>
#include <vector>

#define MAX 55
using namespace std;

int N, M, Answer;
int MAP[MAX][MAX];
bool Cloud_MAP[MAX][MAX];
vector<pair<int, int>> Cloud;
vector<pair<int, int>> Cmd;

int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1};

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        Cmd.push_back(make_pair(a, b));
    }
}

void init_cloud()
{
    Cloud.push_back(make_pair(N - 2, 0));
    Cloud.push_back(make_pair(N - 2, 1));
    Cloud.push_back(make_pair(N - 1, 0));
    Cloud.push_back(make_pair(N - 1, 1));
    Cloud_MAP[N- 2][0] = true;
    Cloud_MAP[N- 2][1] = true;
    Cloud_MAP[N- 1][0] = true;
    Cloud_MAP[N- 1][1] = true;
}

int make_range(int x)
{
    if (x < 0) return N - 1;
    if (x >= N) return 0;
    return x;
}

void move_cloud(int Idx)
{
    int Dir = Cmd[Idx].first;
    int Cnt = Cmd[Idx].second;
    memset(Cloud_MAP, false, sizeof(Cloud_MAP));
    for (int i = 0; i < Cloud.size(); i++)
    {
        int x = Cloud[i].first;
        int y = Cloud[i].second;
        int nx = x;
        int ny = y;
        for (int j = 0; j < Cnt; j++)
        {
            nx += dx[Dir];
            ny += dy[Dir];
            nx = make_range(nx);
            ny = make_range(ny);
        }
        Cloud[i].first = nx;
        Cloud[i].second = ny;
    }
    for (int i = 0; i < Cloud.size(); i++)
    {
        int x = Cloud[i].first;
        int y = Cloud[i].second;
        Cloud_MAP[x][y] = true;
    }
}

void make_rain()
{
    for (int i = 0; i < Cloud.size(); i++)
    {
        int x = Cloud[i].first;
        int y = Cloud[i].second;
        MAP[x][y]++;
    }
}

void water_bug()
{
    for (int i = 0; i < Cloud.size(); i++)
    {
        int x = Cloud[i].first;
        int y = Cloud[i].second;
        int Cnt = 0;
        for (int j = 2; j <= 8; j += 2)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (MAP[nx][ny] >= 1) Cnt++;
        }
        MAP[x][y] += Cnt;
    }
}

void delete_cloud()
{
    Cloud.clear();
}

void make_cloud()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Cloud_MAP[i][j] == true) continue;
            if (MAP[i][j] < 2) continue;
            MAP[i][j] -= 2;
            Cloud.push_back(make_pair(i, j));
        }
    }

    memset(Cloud_MAP, false, sizeof(Cloud_MAP));
    for (int i = 0; i < Cloud.size(); i++)
    {
        int x = Cloud[i].first;
        int y = Cloud[i].second;
        Cloud_MAP[x][y] = true;
    }
}

void find_answer()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Answer += MAP[i][j];
        }
    }
}
 
void solution()
{
    init_cloud();
    for (int i = 0; i < M; i++)
    {
        move_cloud(i);
        make_rain();
        water_bug();
        delete_cloud();
        make_cloud();
    }
    find_answer();
    cout << Answer << endl;
}

void solve()
{
    input();
    solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}