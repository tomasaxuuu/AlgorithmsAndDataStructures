#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkBracketSequence(string &seq) {
	string stack = ""; 
	for (char c : seq) {
		if (c == '(' || c == '[' || c == '{') {
			stack.push_back(c);
			continue;
		}
		if (stack.empty()) {
			return 0;
		}
		if (c == ')' && stack.back() != '(' ||
			c == ']' && stack.back() != '[' ||
			c == '}' && stack.back() != '{') {
			return 0;
		}
		stack.pop_back();
	}
	return stack.empty();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string brsq = "";
	getline(cin, brsq);
	if (checkBracketSequence(brsq)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}