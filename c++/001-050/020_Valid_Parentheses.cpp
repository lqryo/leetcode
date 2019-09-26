#include <iostream>
#include <string>
#include <vector>
#include <map>;

using namespace std;

map<char, char> brackets{ {')','('}, {']','['}, {'}','{'} };

class Solution {
public:
	bool isValid(string s);
};

bool Solution::isValid(string s)
{
	vector<char> stack{'0'};
	for (auto it = s.cbegin(); it < s.cend(); it++)
	{
		if (brackets.find(*it) == brackets.end()) {  //未找到，压栈
			stack.push_back(*it);
		}
		else {  //找到了，和前一个字符进行匹配
			if (brackets[*it] == stack[stack.size() - 1]) { stack.pop_back(); }
			else { stack.push_back(*it); }
		}
	}
	if (stack.size() == 1) return true;
	else return false;
}

int main()
{
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("(]") << endl;
	cout << s.isValid("([)]") << endl;
	cout << s.isValid("{[]}") << endl;

	cin.get();
	return 0;
}

