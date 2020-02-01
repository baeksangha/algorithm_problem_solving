/*
8567. 약수의 개수가 많은 수
1부터 100000까지 수의 약수의 갯수를 모두 구해 num_divs에 저장하고,
1~n까지의 수 중 약수를 가장 많이 가진 수를 max_divs에 저장한다.
그 후 input값에 따라 max_divs[input]을 출력하면 끝난다.

cin, cout을 쓰니 timeout이 나왔는데,
scanf와 printf로 바꾸니 괜찮아졌다.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int test_case;
	int T, n;
	int ans;

	//freopen("input.txt", "r", stdin);

	scanf("%d",&T);

	int num_divs[100001]={1,};
	int max_divs[100001]={1,};

	for(int i=1; i<=100000; i++) {
		double mid = sqrt(i);
		int cnt = 0;
		for(int j=1; j<mid; j++) {
			if(i % j == 0)
				cnt++;
		}
		cnt *= 2;
		if(mid == (int)mid)
			cnt++;
		num_divs[i] = cnt;
		if(num_divs[max_divs[i-1]] <= cnt)
			max_divs[i] = i;
		else
			max_divs[i] = max_divs[i-1];
	}

	for(test_case=1; test_case<=T; test_case++) {
		scanf("%d",&n);
        printf("#%d %d\n", test_case, max_divs[n]);
	}

	return 0;
}
