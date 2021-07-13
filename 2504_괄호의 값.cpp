#include<iostream>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	stack<char>c;
	string input;
	cin >> input;
	int res = 1;
	int temp = 0;
	bool check = true;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '[') {
			res *= 3;
			c.push(input[i]);
		}
		else if (input[i] == '(') {
			res *= 2;
			c.push(input[i]);
		}
	
		else if (input[i] == ']') {
			if (c.empty() || c.top() != '[')
			{
				check = false;
				break;
			}
			else {
				if (input[i - 1] == '[')
					temp += res;
				c.pop();
				res/=3;
			}
		}
		else if (input[i] == ')') {
			if (c.empty() || c.top() != '(') {
				check = false;
				break;
			}
			else {
				if (input[i - 1] == '(')
					temp += res;
				c.pop();
				res /= 2;
			}
		}
	}
	if (!c.empty()||check==false)
		cout << 0 << endl;
	else
		cout << temp << endl;


	return 0;
}