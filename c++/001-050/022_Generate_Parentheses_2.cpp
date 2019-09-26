//改用压栈出栈的方式
//效率提高了一倍（12ms,击败95.67%）

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


//参数：左括号剩余，右括号剩余，保存的结果,当前的括号串
void fun(int left_remain, int right_remain, vector<string>& ans, string& s)
{
//	int spaceNum = 4 - left_remain - right_remain;
//	string space(4*spaceNum, ' ');

	//(left_remain,right_remain,s)
//	cout << space << left_remain <<"  "<< right_remain<<"  "<< s << endl;
	if (left_remain < 0 || right_remain < 0) { s.pop_back(); return;}
	if (left_remain == 0 && right_remain == 0) { ans.push_back(s); s.pop_back(); return; }

	//如果当前字串的右括号多于左括号，则不满足条件，停止递归
	if (left_remain > right_remain) {
		s.pop_back();
		return;
	}
	//如果剩余的字串的右括号多于等于左括号
	else {
		fun(left_remain - 1, right_remain, ans, s += "("); 
		fun(left_remain, right_remain - 1, ans, s += ")"); 
		if (!s.empty()) { s.pop_back(); }
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
	clock_t start = clock();
	ans = s.generateParenthesis(3);
	clock_t end = clock();
	cout << "time consuming:" << end - start << "ms" << endl;

	cin.get();
	return 0;
}