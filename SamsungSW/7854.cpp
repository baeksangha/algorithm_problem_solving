/*
7854. 최약수
조금만 생각하면 되는 문제.
10의 한 자리 약수, 100의 두 자리 약수, ... 를 구하면 된다.
10^9까지의 최약수가 43개라는 점에서 10^9까지의 최약수를 모두
구해야겠다는 힌트를 얻었다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NUM 1000000000

int main() {

	int test_case;
	int T;
	int n, pair, i;
	vector<int> div;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for(int i=1; i<sqrt(NUM); i++) {
		if(NUM % i == 0) {
			pair = NUM/i;
			if((int)pow(10, int(log10(i))+1) % i == 0)
				div.push_back(i);
			if((long long)pow(10, int(log10(pair))+1) % pair == 0)
				div.push_back(pair);
		}
	}

	sort(div.begin(), div.end());

	for(test_case=1; test_case<=T; test_case++) {
		cin >> n;
		
		for(i=0; i<(int)div.size(); i++) {
			if(div[i] > n)
				break;
		}
		cout << "#" << test_case << " " << i << endl;
	}

	return 0;
}
