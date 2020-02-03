/*
종만북 p.168 clocksync
완전 탐색을 이용해 해결하였다.
총 경우의 수는 4^7가지이다.
불가능한 경우를 -1로 출력하라고 했는데 0으로 출력해서
한참 헤맸다..
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> adjust(vector<int> s, vector<int> clock) {

	vector<int> ret(16);

	ret[0] = (clock[0] + (s[0] + s[3] + s[5]) * 3) % 12;
	ret[1] = (clock[1] + (s[0] + s[8]) * 3) % 12;
	ret[2] = (clock[2] + (s[0] + s[5] + s[8]) * 3) % 12;
	ret[3] = (clock[3] + (s[1] + s[6] + s[8] + s[9]) * 3) % 12;
	ret[4] = (clock[4] + (s[2] + s[3] + s[7] + s[8] + s[9]) * 3) % 12;
	ret[5] = (clock[5] + (s[3] + s[7] + s[8] + s[9]) * 3) % 12;
	ret[6] = (clock[6] + (s[3] + s[4]) * 3) % 12;
	ret[7] = (clock[7] + (s[1] + s[3] + s[4] + s[7]) * 3) % 12;
	ret[8] = (clock[8] + (s[4]) * 3) % 12;
	ret[9] = (clock[9] + (s[1] + s[9]) * 3) % 12;
	ret[10] = (clock[10] + (s[2] + s[4]) * 3) % 12;
	ret[11] = (clock[11] + (s[1]) * 3) % 12;
	ret[12] = (clock[12] + (s[4]) * 3) % 12;
	ret[13] = (clock[13] + (s[9]) * 3) % 12;
	ret[14] = (clock[14] + (s[2] + s[5] + s[6] + s[7]) * 3) % 12;
	ret[15] = (clock[15] + (s[2] + s[5] + s[6] + s[7]) * 3) % 12;

	return ret;
}

int synch(vector<int> button, vector<int> clock, int idx) {
	
	int ret = 9999;
	vector<int> after_sync = adjust(button, clock);

	if(idx == 1 || idx == 4)
		return synch(button, clock, idx+1);

	if(idx == 9) {
		for(int i=0; i<16; i++) {
			if(after_sync[i] != 0)
				return 9999;
		}
		int sum = accumulate(button.begin(), button.end(), 0);
		return min(ret, sum);
	}

	

	for(int i=0; i<4; i++) {
		button[idx] = i;
		ret = min(ret, synch(button, clock, idx+1));
	}

	return ret;
}

int main() {

	int test_case;
	int T;
	vector<int> clock(16);
	vector<int> button(10);
	int ans;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {

		for(int i=0; i<16; i++)
			cin >> clock[i];

		if((clock[14] != clock[15]) || (clock[8] != clock[12]))
			ans = -1;
		else {
			button[4] = (12 - clock[8]) / 3;
			button[1] = (12 - clock[11]) / 3;
			button[9] = (12 - clock[13]) / 3;
			
			ans = synch(button, clock, 0);
		}
		if(ans == 9999)
			ans = -1;
		cout << ans << endl;
	}

	return 0;
}
