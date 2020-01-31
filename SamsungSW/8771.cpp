/*
8771. 덧셈 문제
ios::sync_with_stdio(false)를 쓰고 cout을 써도 시간 초과가 났는데,
cin, cout을 scanf, printf로 바꾸니 통과가 된 문제이다.
*/

#include <iostream>
using namespace std;

int main() {

	int test_case;
	int T;
	long long n, a, b;
	long long ans;

	//freopen("input.txt", "r", stdin);

	scanf("%d",&T);

	for(test_case=1; test_case<=T; test_case++) {

		ans = 0;
		scanf("%ld %ld %ld", &n, &a, &b);

		if((n > 1 && a <= b) || (n == 1 && a == b))
			ans = (b-a)*(n-2) + 1;

		printf("#%d %ld\n", test_case, ans);
	}

	return 0;
}
