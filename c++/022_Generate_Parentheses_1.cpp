//使用回溯法
//用时28ms，击败32.19%用户

#include <iostream>
#include <vector>
#include <string>

using namespace std;


//参数：左括号剩余，右括号剩余，保存的结果,当前的括号串
void fun(int left_remain, int right_remain, vector<string>& ans, string s)
{
	if (left_remain < 0 || right_remain < 0) { return; }
	if (left_remain == 0 && right_remain == 0) { ans.push_back(s); return; }

	//如果当前字串的右括号多于左括号，则不满足条件，停止递归
	if (left_remain > right_remain) {
		return;
	}
	//如果剩余的字串的右括号多于等于左括号
	else {
		fun(left_remain - 1, right_remain, ans, s + "(");
		fun(left_remain, right_remain - 1, ans, s + ")");
	}

}

class Solution {
public:
	vector<string> generateParenthesis(int n);
};

vector<string> Solution::generateParenthesis(int n)
{

	string s("");
	vector<string> ans{};

	fun(n, n, ans, s);
	return ans;
}

int main()
{

	Solution s;
	vector<string> ans;
	ans = s.generateParenthesis(3);

	cin.get();
	return 0;
}