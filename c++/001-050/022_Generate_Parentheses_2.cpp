//����ѹջ��ջ�ķ�ʽ
//Ч�������һ����12ms,����95.67%��

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


//������������ʣ�࣬������ʣ�࣬����Ľ��,��ǰ�����Ŵ�
void fun(int left_remain, int right_remain, vector<string>& ans, string& s)
{
//	int spaceNum = 4 - left_remain - right_remain;
//	string space(4*spaceNum, ' ');

	//(left_remain,right_remain,s)
//	cout << space << left_remain <<"  "<< right_remain<<"  "<< s << endl;
	if (left_remain < 0 || right_remain < 0) { s.pop_back(); return;}
	if (left_remain == 0 && right_remain == 0) { ans.push_back(s); s.pop_back(); return; }

	//�����ǰ�ִ��������Ŷ��������ţ�������������ֹͣ�ݹ�
	if (left_remain > right_remain) {
		s.pop_back();
		return;
	}
	//���ʣ����ִ��������Ŷ��ڵ���������
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