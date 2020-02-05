/*
1223. 계산기(2)
스택으로 계산기 만드는 문제.
1) 중위표기법 -> 후위표기법으로 바꾸었고,
2) 후위표기법을 계산하였다.
같은 코드로 1224.계산기(3)도 해결된다.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int char2num(char a) {

	switch(a) {
		case '0' : return 0;
		case '1' : return 1;
		case '2' : return 2;
		case '3' : return 3;
		case '4' : return 4;
		case '5' : return 5;
		case '6' : return 6;
		case '7' : return 7;
		case '8' : return 8;
		case '9' : return 9;
	}
	return -1;
}

int priority(char oper) {
	if(oper == '+' || oper == '-')
		return 1;
	else if(oper == '*')
		return 2;
	else
		return 0;
}

int main() {

	int test_case;
	int T, n;
	string input;
	stack<char> st;
	stack<int> calc;

	freopen("input.txt", "r", stdin);

	for(test_case=1; test_case<=3; test_case++) {

		string ans;
		cin >> n;
		cin >> input;

		for(int i=0; i<n; i++) {
			if(input[i] >= '0' && input[i] <= '9')
				ans += input[i];
			else if(input[i] == '(')
				st.push('(');
			else if(input[i] == ')') {
				while(st.top() != '(') {
					ans += st.top();
					st.pop();
				}
				st.pop();
			}
			else {
				while(!st.empty() && priority(st.top()) >= priority(input[i])) {
					ans += st.top();
					st.pop();
				}
				st.push(input[i]);
			}
		}

		while(!st.empty()) {
			ans += st.top();
			st.pop();
		}

		for(int i=0; i<ans.length(); i++) {
			if(ans[i] >= '0' && ans[i] <= '9')
				calc.push(char2num(ans[i]));
			else {
				if(ans[i] == '+') {
					int op1 = calc.top();
					calc.pop();
					int op2 = calc.top();
					calc.pop();
					calc.push(op1 + op2);
				}
				else {
					int op1 = calc.top();
					calc.pop();
					int op2 = calc.top();
					calc.pop();
					calc.push(op1 * op2);
				}
			}
		}

		cout << "#" << test_case << " " << calc.top() << endl;
	}

	return 0;
}
