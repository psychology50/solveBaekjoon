#include <iostream>
#include <vector>
using namespace std;

int map[19][19];

vector<int> dx[] = {{0,0},{-1,1},{-1,1},{1,-1}};
vector<int> dy[] = {{-1,1},{0,0},{1,-1},{1,-1}};


int search(int x, int y, int dir1, int dir2, int count){
    if(count > 5) return 999;

    int nx = x + dx[dir1][dir2];
    int ny = y + dy[dir1][dir2];
    if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) return count;
    if(map[nx][ny] == map[x][y]) count = search(nx,ny,dir1,dir2,count+1); 
		
    return count;
}

int startSetting(int x, int y){
    int ans = 0;
		
    for(int i = 0; i < 4; i++){
        int val = 1; 
        for(int j = 0; j < 2; j++){
            int nx = x + dx[i][j];
            int ny = y + dy[i][j];
            if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) continue;
            
            if(map[x][y] == map[nx][ny]) val += search(nx,ny,i,j,1);
        }
         
        if(val == 5) {
            ans = map[x][y];
            break;
        }
    }   
    return ans;
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int ans, ansX, ansY;
    ans = 0;
    ansX = ansY = 99;
    for(int i = 0; i < 19; i++) for(int j = 0; j < 19; j++) cin >> map[i][j];

    for(int i = 0; i < 19; i++) for(int j = 0; j < 19; j++){
        if (map[i][j] == 0) continue;
        int val = startSetting(i,j);
        if(val != 0) {
            if(j < ansY){
                ans = val;
                ansX = i;
                ansY = j;
            }
        }
    }
    
    if(ans){
        cout << ans << "\n";
        cout << ansX+1 <<" " << ansY+1;
    }
    else cout << "0";
}