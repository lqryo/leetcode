//�ο���https://blog.csdn.net/chao_shine/article/details/88605552

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
	//�ȶ����������д���
	if (divident == INT_MIN && divisor == -1)
		return INT_MAX;

	int sign; //1��ʾ���Ϊ����-1��ʾ���Ϊ��
	if (divident >= 0 && divisor >= 0 || divident <= 0 && divisor <= 0) {
		sign = 1;
	}
	else {
		sign = -1;
	}

	//�Գ����ͱ�����ȡ����ֵ
	long long divid = fabs(divident);
	long long divis = fabs(divisor);

	long long quotient = 0; //��
	while (divid >= divis)
	{
		long long temp = divis;

		//ֻҪ���ܼ����͵ô����
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