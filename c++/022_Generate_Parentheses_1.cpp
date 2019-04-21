//ʹ�û��ݷ�
//��ʱ28ms������32.19%�û�

#include <iostream>
#include <vector>
#include <string>

using namespace std;


//������������ʣ�࣬������ʣ�࣬����Ľ��,��ǰ�����Ŵ�
void fun(int left_remain, int right_remain, vector<string>& ans, string s)
{
	if (left_remain < 0 || right_remain < 0) { return; }
	if (left_remain == 0 && right_remain == 0) { ans.push_back(s); return; }

	//�����ǰ�ִ��������Ŷ��������ţ�������������ֹͣ�ݹ�
	if (left_remain > right_remain) {
		return;
	}
	//���ʣ����ִ��������Ŷ��ڵ���������
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