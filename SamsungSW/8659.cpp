/*
8659. GCD
GCD를 빙자한 피보나치수열 문제.
*/

#include <iostream>
using namespace std;

int main() {

	int test_case;
	int T;
	int k;

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for(test_case=1; test_case<=T; test_case++) {

		long long first = 2;
		long long sec = 1;

		cin >> k;

		for(int i=1; i<k; i++) {
			first = first + sec;
			sec = first - sec;
		}

		cout << "#" << test_case << " " << first << " " << sec << endl;
	}

	return 0;
}
