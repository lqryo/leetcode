/*
*****�����Ҷ�s���е���*********
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows);
};

string Solution::convert(string s, int numRows)
{
	if (numRows == 1) {
		return s;
	}

	bool down = true;  //��ʾ�ַ����з���
	int row = 1;  //��ʾ�ַ�������
	string ans = "";

	int realRow = min(numRows, static_cast<int>(s.length()));

	vector<string> Result(realRow);
	for(char c : s)
	{
		Result[row-1] += c;
		//����ַ����������Ų��������һ��
		//����������������1
		if (down && row == realRow) {
			row--;
			down = false;
		}

		else if (!down && row == 1)
		{
			row++;
			down = true;
		}

		//�����½�
		else if (down)
		{
			row++;
		}
		else if (!down)
		{
			row--;
		}
	}

	for (size_t i = 0; i < realRow; i++)
	{
		ans += Result[i];
	}
	return ans;
}


int main()
{
	Solution s;
	cout << s.convert("LEETCODEISHIRING", 3)<<endl;
	cout << s.convert("LEETCODEISHIRING", 4) << endl;
	cout << s.convert("A", 2)<<endl;
	cin.get();

	return 0;
}




