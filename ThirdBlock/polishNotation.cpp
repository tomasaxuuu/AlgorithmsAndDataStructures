#include <iostream>
#include <string>
#include <stack>
using namespace std;

int polishN(string strNumOper) {
	stack<int> stack;
	for (int i = 0; i < strNumOper.size(); i++) {
		if (isdigit(strNumOper[i])) {
			stack.push(strNumOper[i] - '0');
		}
		else if (strNumOper[i] != ' ') {
			const int first = stack.top();
			stack.pop();
			const int second = stack.top();
			stack.pop();
			switch (strNumOper[i]) {
			case '+':
				stack.push(first + second);
				break;
			case '-':
				stack.push(-(first - second));
				break;
			case '*':
				stack.push(first * second);
				break;
			case '/':
				stack.push(first / second);
				break;
			}
		}
	}
	return stack.top();
}
int main() {
	string enterStr = "";
	getline(cin, enterStr);
	cout << polishN(enterStr);
	return 0;
}