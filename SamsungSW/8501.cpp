/*
8501. 은비의 동전 뒤집기
복잡해 보이나, D4 난이도에 있다는 것에서 힌트를 얻어 점화식을 세운 문제.
n이 1000까지라 시간 제한에 걸리지 않은 것 같다.
점화식을 세워 해결하는 간단한 문제.
*/

#include <iostream>
using namespace std;

#define NUM 1000000007

int main() {

	int test_case;
	int T, n;
	long long arr[1001];
	long long fact[1001];

	freopen("input.txt", "r", stdin);

	fact[1] = 1;
	arr[1] = 0;
	// first, get 1!%NUM ~ 1000!%NUM
	for(int i=2; i<=1000; i++)
		fact[i] = (fact[i-1] * i) % NUM;
	for(int i=2; i<=1000; i++)
		arr[i] = (((i * arr[i-1]) % NUM) + (((i/2) * fact[i-1]) % NUM)) % NUM;

	cin >> T;

	for(test_case=1; test_case<=1000; test_case++) {
		cin >> n;
		cout << "#" << test_case << " " << arr[n] << endl;
	}

	return 0;
}
