/*
8382. 방향 전환
규칙 찾기 문제.
*/

#include <iostream>
using namespace std;

int max(int a, int b) {
	if(a >= b)
		return a;
	return b;
}

int main() {

	int test_case;
	int T;
	int x1, x2, y1, y2;
	int dif_x, dif_y;
	int ans;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {
		cin >> x1 >> y1 >> x2 >> y2;
		dif_x = abs(x2-x1);
		dif_y = abs(y2-y1);
	
		if(dif_x % 2 == dif_y % 2)
			ans = max(dif_x, dif_y) * 2;
		else
			ans = max(dif_x, dif_y)*2 - 1;

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}
