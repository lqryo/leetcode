
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str);
};

int Solution::myAtoi(string str)
{
	int result = 0;
	bool start = false;  //是否开始进行了转换
	bool ispostive = true; //是否为正数

	for (char c : str) 
	{
		switch (c)
		{
		case ' ':
			if (!start) continue;
			else return result;
			break;

		case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
		{
			start = true;
			int num = c - '0';

			if (ispostive)
			{
				//判断是否溢出
				if (result>INT_MAX/10 || (result == INT_MAX / 10 && num > 7))
				{
					return INT_MAX;
				}
				result = result * 10 + num;
			}
			else {
				if (result < INT_MIN / 10 || (result == INT_MIN / 10 && num > 8))
				{
					return INT_MIN;
				}
				result = result * 10 - num;
			}				
		}
		break;

		case '-':
			if (!start) { ispostive = false; start = true; }
			else return result;			
			break;

		case '+':
			if (!start) { ispostive = true;start = true; }
			else return result;
			break;

		default:
			return result;
		}
	}

	return result;
}

int main()
{
	//string s("我是中国人1");
	//cout << s.size() << endl;

	Solution s;
	cout << s.myAtoi("42") << endl;
	cout << s.myAtoi("   -42") << endl;
	cout << s.myAtoi("4193 with words") << endl;
	cout << s.myAtoi("words and 987") << endl;
	cout << s.myAtoi("-91283472332") << endl;

	cin.get();
	return 0;
}

