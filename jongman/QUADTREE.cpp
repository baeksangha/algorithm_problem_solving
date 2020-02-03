/*
종만북 189쪽에 있는 분할정복 문제이다.
문제 읽기가 힘들어서 그렇지 문제 자체는 정말 쉽다.
1 -> 2 -> 3 -> 4의 순서를 3 -> 4 -> 1 -> 2로 바꾸면 되는 문제.
*/

#include <iostream>
#include <string>
using namespace std;

string rearrange(string s) {

	int n = s.length();

	if(n == 1)
		return s;

	string sub[4];
	int st = 1, cnt = 0;
	int idx = 0;

	for(int i=1; i<n; i++) {
		if(s[i] == 'x') {
			if(cnt == 0)
				cnt += 4;
			else
				cnt += 3;
			continue;
		}
		else if(cnt > 0)
			cnt--;

		if(cnt == 0) {
			sub[idx++] = s.substr(st, i-st+1);
			st = i+1;
		}
	}

	return "x" + rearrange(sub[2]) + rearrange(sub[3]) + rearrange(sub[0]) + rearrange(sub[1]);
}

int main() {

	int test_case;
	int T;
	string s, ans;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {

		cin >> s;
		if(s.length() == 1)
			ans = s;
		else
			ans = rearrange(s);

		cout << ans << endl;
	}

	return 0;
}
