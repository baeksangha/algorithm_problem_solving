/*
8568. 3으로 나눈 순열
아이디어는 이렇다.
자리별로 one, two, zero의 배열을 만들어 안 맞는 수일 때 그 수를 vector에 입력.
그 후 한 번에 스위칭이 되면 +1씩 더하고 그 수들을 벡터에서 제거
남은 벡터의 원소 수를 더한 후 /3 *2하면 끝.

알고리즘은 그럴싸한데, 구현이 깔끔하지 못한 것 같다.
다음에(?) 다시 고민해봐야겠다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int test_case;
	int T;
	int n, p, rem;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {

		vector<int> one, two, zero;
		int ans = 0;

		cin >> n;

		for(int i=0; i<n; i++) {
			cin >> p;
			rem = p % 3;
			if(i % 3 == 0 && rem != 1)
				one.push_back(rem);
			else if(i % 3 == 1 && rem != 2)
				two.push_back(rem);
			else if(i % 3 == 2 && rem != 0)
				zero.push_back(rem);
		}

		vector<int>::iterator it12, it10, it21, it20, it01, it02;
		
		while(1) {
			it12 = find(one.begin(), one.end(), 2);
			it21 = find(two.begin(), two.end(), 1);
			if(it12 != one.end() && it21 != two.end()) {
				one.erase(it12);
				two.erase(it21);
				ans++;
			}
			else
				break;
		}
		while(1) {
			it10 = find(one.begin(), one.end(), 0);
			it01 = find(zero.begin(), zero.end(), 1);
			if(it10 != one.end() && it01 != zero.end()) {
				one.erase(it10);
				zero.erase(it01);
				ans++;
			}
			else
				break;
		}
		while(1) {
			it20 = find(two.begin(), two.end(), 0);
			it02 = find(zero.begin(), zero.end(), 2);
			if(it20 != two.end() && it02 != zero.end()) {
				two.erase(it20);
				zero.erase(it02);
				ans++;
			}
			else
				break;
		}

		ans += ((int)one.size() + (int)two.size() + (int)zero.size()) / 3 * 2;

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}
