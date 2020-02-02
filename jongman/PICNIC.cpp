/*
종만북 p155 PICNIC(下)
n의 최댓값이 100이라 is_friend배열을 100x100으로 만들어 신분 저장
중복을 방지하지 위해 처음 target을 지정해줌.
*/

#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> taken, vector<vector<int>> &is_friend) {

	int target;
	int n = (int)taken.size();
	int std = 1;
	int ret = 0;

	for(int i=0; i<n; i++) {
		if(taken[i] == 0) {
			target = i;
			std = 0;
			break;
		}
	}
	if(std == 1)
		return 1;

	for(int i=0; i<n; i++) {
		if(taken[i] == 0 && is_friend[i][target] == 1) {
			taken[i] = taken[target] = 1;
			ret += countPairs(taken, is_friend);
			taken[i] = taken[target] = 0;
		}
	}

	return ret;
}

int main() {

	int test_case;
	int T;

	int n, m;
	int f1, f2;
	int ans;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {

		cin >> n >> m;
		vector<vector<int>> is_friend(n, vector<int>(n));
		vector<int> taken(n, 0);

		for(int i=0; i<m; i++) {
			cin >> f1 >> f2;
			is_friend[f1][f2] = is_friend[f2][f1] = 1;
		}

		ans = countPairs(taken, is_friend);

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}
