//参考：https://blog.csdn.net/chao_shine/article/details/88605552

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int divide(int divident, int divisor);
};

int Solution::divide(int divident, int divisor)
{
	//先对溢出情况进行处理
	if (divident == INT_MIN && divisor == -1)
		return INT_MAX;

	int sign; //1表示结果为正，-1表示结果为负
	if (divident >= 0 && divisor >= 0 || divident <= 0 && divisor <= 0) {
		sign = 1;
	}
	else {
		sign = -1;
	}

	//对除数和被除数取绝对值
	long long divid = fabs(divident);
	long long divis = fabs(divisor);

	long long quotient = 0; //商
	while (divid >= divis)
	{
		long long temp = divis;

		//只要还能减，就得寸进尺
		for (size_t i = 0; temp <= divid; i++)
		{
			divid -= temp;
			quotient += (1 << i);
			temp = temp << 1;
		}
	}

	return sign * quotient;
}


int main(int argc,char* argv[])
{

	Solution s;
	cout << s.divide(10, 3) << endl;
	cout << s.divide(7, -3) << endl;
	cout << s.divide(1, 1) << endl;

	getchar();

	return 0;
}