//�ο���https://leetcode-cn.com/problems/multiply-strings/solution/c-shu-shi-cheng-fa-dai-ma-jian-ji-you-ya-yi-dong-b/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	string multiply(string num1, string num2);
};

string Solution::multiply(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	string res(n1 + n2, '0');

	for (size_t i = n2 - 1; i >= 0; i--)
	{
		for (size_t j = n1 - 1; j >= 0 ; j--)
		{
			int temp = (res[i+j+1]-'0')+ (num1[j] - '0')*(num2[i] - '0');
			res[i + j + 1] = temp % 10 + '0';
			res[i + j] += temp / 10; //ǰһλ���Ͻ�λ��res[i+j]�Ѿ���ʼ��Ϊ'0'������int�����Զ�ת��Ϊchar�����Դ˴�����'0'
		}
	}

	//ȥ����λ'0'
	for (size_t i = 0; i < n1+n2; i++)
	{
		if (res[i] != '0')
			return res.substr(i);
	}
	return "0";


}



int main()
{

	Solution s;
	string num1{ "2" };
	string num2{ "3" };
	cout << s.multiply(num1, num2) << endl;

	cin.get();
	return 0;
}


