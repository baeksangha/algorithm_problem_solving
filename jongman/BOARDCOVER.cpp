/*
종만북 159쪽의 게임판 덮기 문제이다.
brute force 단원이라 그런지 문제 조건이 상당히 유하다.
판의 크기가 20*20임에도 불구하고 블록의 총 갯수가 50개로 제한되어 있다.
블록 갯수의 제한이 없었다면 시간 초과가 났을 것 같다.
O(n^2)

아이디어는 이렇다.
중복을 방지하기 위해 판의 처음부터 블록을 채워나가는데, 원래 ㄱ자 블록은 10방향으로
놓을 수 있지만 이 제한을 두면 둘 수 있는 경우의 수가 4가지로 확 줄어든다.
이렇게 해서 하나 하나 되는 것을 세어나갔다.
*/

#include <iostream>
#include <vector>
using namespace std;

int dir_x[6][2] = {{1, 1},{0, 1}, {0, 1}, {1, 1}};
int dir_y[6][2] = {{0, -1}, {1, 0}, {1, 1}, {0, 1}};


int isFit(int x, int y, vector<vector<char>> &map) {

	int r_x = (int)map.size();
	int r_y = (int)map[0].size();

	if(x >= 0 && x < r_x && y >= 0 && y < r_y && map[x][y] == '.')
		return 1;
	return 0;
}

int boardCover(int blocks, vector<vector<char>> map) {

	if(blocks == 0)
		return 1;

	int ret = 0;
	int h = (int)map.size();
	int w = (int)map[0].size();
	int st_x, st_y;

	for(int i=0; i<h*w; i++) {
		if(map[i/w][i%w] == '.') {
			st_x = i / w;
			st_y = i % w;
			break;		
		}
	}

	for(int i=0; i<4; i++) {
		int x1 = st_x + dir_x[i][0];
		int y1 = st_y + dir_y[i][0];
		int x2 = st_x + dir_x[i][1];
		int y2 = st_y + dir_y[i][1];
		if(isFit(st_x, st_y, map) && isFit(x1, y1, map) && isFit(x2, y2, map)) {
			map[st_x][st_y] = map[x1][y1] = map[x2][y2] = '#';
			ret += boardCover(blocks-1, map);
			map[st_x][st_y] = map[x1][y1] = map[x2][y2] = '.';
		}
	}

	return ret;
}

int main() {

	int test_case;
	int T;
	int h, w;
	int ans;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {

		cin >> h >> w;
		vector<vector<char>> map(h, vector<char>(w));
		int num_dots, blocks;

		num_dots = 0;

		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin >> map[i][j];
				if(map[i][j] == '.')
					num_dots++;
			}
		}

		if(num_dots % 3 != 0)
			ans = 0;
		else {
			blocks = num_dots / 3;
			ans = boardCover(blocks, map);
		}

		cout << ans << endl;
	}

	return 0;
}
