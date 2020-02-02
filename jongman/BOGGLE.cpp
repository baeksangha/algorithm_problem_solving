#include <iostream>
#include <string>
using namespace std;

char word[5][5];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int isInRange(int x, int y) {
	if(0 <= x && x < 5 && 0 <= y && y < 5)
		return 1;
	return 0;
}

string hasWord(int x, int y, string str) {

	if(str.length() == 0)
		return "YES";

	int new_x, new_y;

	for(int i=0; i<8; i++) {
		new_x = x + dx[i];
		new_y = y + dy[i];

		if(isInRange(new_x, new_y) && word[new_x][new_y] == str[0]) {
			if(hasWord(new_x, new_y, str.substr(1)) == "YES")
				return "YES";
		}
	}

	return "NO";
}

int main() {

	//freopen("input.txt","r", stdin);

	int T;
	int n;
	string str_input, ret;

	cin >> T;

	for(int test_case=1; test_case<=T; test_case++) {

		// input word map
		for(int i=0; i<5; i++) {
			for(int j=0; j<5; j++) {
				cin >> word[i][j];
			}
		}

		cin >> n;

		// find string in word map
		for(int iter=0; iter<n; iter++) {
			cin >> str_input;
			ret = "NO";
			for(int i=0; i<5; i++) {
				for(int j=0; j<5; j++) {
					if(word[i][j] == str_input[0]) {
						ret = hasWord(i, j, str_input.substr(1));
						if(ret == "YES")
							break;
					}
				}
				if(ret == "YES")
					break;
			}
			cout << str_input << " " << ret << endl;
		}
	}
 
	return 0;
}
