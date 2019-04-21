/*
*****从左到右对s进行迭代*********
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

	bool down = true;  //标示字符排列方向
	int row = 1;  //标示字符所在行
	string ans = "";

	int realRow = min(numRows, static_cast<int>(s.length()));

	vector<string> Result(realRow);
	for(char c : s)
	{
		Result[row-1] += c;
		//如果字符正在向下排并且在最后一行
		//将方向反向并且行数减1
		if (down && row == realRow) {
			row--;
			down = false;
		}

		else if (!down && row == 1)
		{
			row++;
			down = true;
		}

		//正在下降
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




