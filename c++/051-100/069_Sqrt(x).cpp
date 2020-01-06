// 参考：https://leetcode-cn.com/problems/sqrtx/solution/niu-dun-die-dai-fa-by-loafer/

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	int a;
//	static int time;
	//牛顿迭代法
	int mySqrt(int x) {
		a = x;
		if (x == 0) return 0;
		return (int)sqrts(x);
	}

	double sqrts(double x) {
		double res = (x + a / x) / 2;

//		cout << "time is " << time++ <<"; res is " << res <<endl;

		if (res == x) {
			return x;
		}
		else {
			return sqrts(res);
		}
	}
};

//int Solution::time = 0;


int main()
{
	Solution s;
	//cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(10) << endl;
	//cout << s.mySqrt(100) << endl;
	//cout << s.mySqrt(101) << endl;
	//cout << s.mySqrt(20) << endl;
	//cout << s.mySqrt(70) << endl;
	
	cin.get();
	return 0;

}