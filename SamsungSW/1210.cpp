/*
1210. Ladder1
왜 D4에 있는지 의문인 문제이다.
그냥 배열 문제..
풀이라 할것도 없다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	for(test_case=1; test_case<=10; test_case++) {

		vector<vector<int>> map(100, vector<int>(100));
		int x, y;

		cin >> T;
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				cin >> map[i][j];
			}
		}

		x = 99;

		for(int i=0; i<100; i++) {
			if(map[99][i] == 2) {
				y = i;
				break;
			}
		}

		while(x > 0) {
			x--;
			if(y > 0 && map[x][y-1] == 1) {
				while(map[x][y] == 1)
					y--;
				y++;
			}
			else if(y < 100 && map[x][y+1] == 1) {
				while(map[x][y] == 1 && y < 100)
					y++;
				y--;
			}
		}

		cout << "#" << test_case << " " << y << endl;
	}

	return 0;
}
