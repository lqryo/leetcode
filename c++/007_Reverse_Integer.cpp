/*
*	弹出和推入数字& 溢出前进行检测
*/
#include <iostream>

using namespace std;
class Solution {
public:
	int reverse(int x);
};


int Solution::reverse(int x)
{
	int rev = 0;
	while (x !=0)
	{
		int quotinent = x / 10;
		int remainder = x % 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && remainder > 7)) {
			return 0;
		}
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && remainder < -8)) {
			return 0;
		}
		rev = rev * 10 + remainder;
		x /= 10;

	}

	return rev;
}


int main()
{

	int a = -12;

//	cout << a / 10 << endl;  //输出-1
//	cout << a % 10 << endl;  //输出-2
	Solution s;
	cout << s.reverse(123) << endl;
	cout << s.reverse(-123) << endl;
	cout << s.reverse(120) << endl;


	cin.get();
}

