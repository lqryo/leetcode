//参考：https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n);

private:
	//快速幂算法，递归
	double fastPow(double x, long long n)
	{
		if (n == 0) return 1.0;
		double half = fastPow(x, n / 2);
		if (n % 2 == 0) {
			return half * half;
		}
		else {
			return half * half * x;
		}
	}


};



double Solution::myPow(double x, int n)
{
	long long N = n;
	if (N < 0) {
		x = 1 / x;
		N = -N;
	}
	return fastPow(x, N);
}



int main()
{




	cin.get();
	return 0;
}


